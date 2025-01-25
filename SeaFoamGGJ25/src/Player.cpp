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
}
