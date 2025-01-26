#include "Player.h"

Player::Player() : m_floatVelocity(sf::Vector2f(0.0f, -1.0f))
{
	m_health = MAX_HEALTH;
	m_spriteOffset = sf::Vector2f(30.0f, 30.0f);
}

void Player::setupSprite(sf::Texture &t_texture)
{
	m_sprite.setTexture(t_texture);
	m_sprite.setPosition(0.0f, 0.0f);
	m_sprite.setScale(0.1f, 0.1f);
	m_sprite.setRotation(45);
	m_sprite.setOrigin(1194.0f, 834.0f);
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

	if (m_health <= 0)
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
	updatePosition();
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
	m_sprite.setPosition(m_position + m_spriteOffset);
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
	m_sprite.setPosition(m_position + m_spriteOffset);
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
