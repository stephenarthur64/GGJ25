#include "Geiser.h"

void Geiser::setupBody(sf::Vector2f t_pos)
{
	m_position = t_pos;

	m_body.setFillColor(sf::Color::Cyan);
	m_body.setSize(sf::Vector2f(100.0f, 175.0f));
	m_body.setPosition(m_position);
}
