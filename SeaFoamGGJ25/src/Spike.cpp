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
	if (m_orientation == 1)
	{
		m_body.setRotation(180);
	}
}
