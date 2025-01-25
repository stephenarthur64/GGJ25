#include "Geiser.h"

void Geiser::setupBody(sf::Vector2f t_pos)
{
	m_position = t_pos;

	m_body.setFillColor(sf::Color::Cyan);
	m_body.setSize(sf::Vector2f(100.0f, 175.0f));
	m_body.setPosition(m_position);

	bubble.setupBody();
	bubble.spawn(m_position);
}

sf::CircleShape Geiser::getBubble()
{
	return bubble.getBody();
}

sf::FloatRect Geiser::getBubbleBounds()
{
	return bubble.getBody().getGlobalBounds();
}

void Geiser::moveBubble()
{
	bubble.move();
}

void Geiser::disableBubble()
{
	bubble.disable();
}
