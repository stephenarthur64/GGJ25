#include "Player.h"

Player::Player() : m_floatVelocity(sf::Vector2f(0.0f, -1.0f))
{
	m_health = MAX_HEALTH;
}

void Player::floatUp()
{
	if (m_velocity.x == 0.0f)
	{
		m_velocity = m_floatVelocity;
	}
}

void Player::movementStop()
{
	m_velocity.x = 0.0f;
}

void Player::damaged(int t_damage)
{
	if (m_health > 0)
	{
		m_health -= t_damage;
	}

	if (m_health == 0)
	{
		die();
	}

	if (m_velocity == m_floatVelocity)
	{
		m_position.y -= m_velocity.y * 100;
	}
	else
	{
		m_position.x -= m_velocity.x * 20;
		m_position.y -= m_velocity.y * 20;
	}
	m_body.setPosition(m_position);
}

void Player::healed(int t_heal)
{
	if (m_health < MAX_HEALTH)
	{
		m_health++;
	}
}

void Player::stopped()
{
	m_position -= m_velocity;
	m_body.setPosition(m_position);
}

void Player::scrollPosition(int t_scrollingX, float t_viewY, sf::View& t_view)
{
	if (m_position.x > t_scrollingX)
	{
		t_view.setCenter(m_position.x, t_viewY);
	}
}

void Player::die()
{
	m_position.x = -10000.0f;
	m_body.setPosition(m_position);
}

bool Player::isDead()
{
	if (m_health == 0)
	{
		return true;
	}
	return false;
}

int Player::getHealth()
{
	return m_health;
}
