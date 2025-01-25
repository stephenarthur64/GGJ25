#include "Player.h"

Player::Player() : m_floatVelocity(sf::Vector2f(0.0f, -1.0f)), m_health(5)
{

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
	m_body.setFillColor(sf::Color::Red);
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
	m_body.setFillColor(sf::Color::Blue);
}

void Player::stopped()
{
	m_position -= m_velocity;
	m_body.setPosition(m_position);
}
