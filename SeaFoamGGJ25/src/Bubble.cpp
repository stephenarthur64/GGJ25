#include "Bubble.h"

Bubble::Bubble()
{
	m_speed = -2.0f;
}

void Bubble::setupBody()
{
	m_body.setRadius(30.0f);
	m_body.setFillColor(sf::Color::Green);
}

void Bubble::spawn(sf::Vector2f t_pos)
{
	m_position = t_pos;
	m_body.setPosition(m_position);
}

void Bubble::move()
{
	m_velocity.y = m_speed;
	m_position += m_velocity;
	m_body.setPosition(m_position);
}

sf::CircleShape Bubble::getBody()
{
	return m_body;
}
