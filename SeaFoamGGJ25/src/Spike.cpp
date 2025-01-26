#include "Spike.h"

Spike::Spike()
{
}

void Spike::setupBody(int t_orientation, sf::Vector2f t_pos, sf::Vector2f t_size)
{
	m_size = t_size;
	m_orientation = t_orientation;
	m_position = t_pos;

	m_body.setFillColor(sf::Color::Black);
	m_body.setSize(m_size);
	m_body.setPosition(m_position);
	m_spriteOffset = sf::Vector2f(300.0f, 250.0f);
	m_sprite.setRotation(180);
	if (m_orientation == 1)
	{
		m_spriteOffset = sf::Vector2f(-300.0f, -250.0f);
		m_body.setRotation(180);
		m_sprite.setRotation(0);

	}
}

void Spike::setupSprite(sf::Texture& t_texture)
{
	m_sprite.setTexture(t_texture);
	m_sprite.setPosition(m_position + m_spriteOffset);
	m_sprite.setScale(0.25f, 0.2f);
}
