#include "Bubble.h"

Bubble::Bubble()
{
	m_speed = -2.0f;
	m_spriteOffset = sf::Vector2f(-126.0f, -56.0f);
}

void Bubble::setupBody()
{
	m_body.setRadius(30.0f);
	m_body.setFillColor(sf::Color::Green);
}

void Bubble::setupSprite(sf::Texture& t_texture)
{
	m_sprite.setTexture(t_texture);
	m_sprite.setScale(0.14f, 0.14f);
	m_sprite.setColor(sf::Color(255, 255, 255, 76));
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
	m_sprite.setPosition(m_position + m_spriteOffset);
}

void Bubble::disable()
{
	m_position.x = 100000000000.0f;
}

sf::CircleShape Bubble::getBody()
{
	return m_body;
}
