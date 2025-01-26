#include "Geiser.h"

void Geiser::setupBody(sf::Vector2f t_pos)
{
	m_position = t_pos;
	m_spriteOffset = sf::Vector2f(-230.0f, -90.0f);

	m_body.setFillColor(sf::Color::Cyan);
	m_body.setSize(sf::Vector2f(100.0f, 175.0f));
	m_body.setPosition(m_position);

	bubble.setupBody();
	bubble.spawn(m_position);
}

void Geiser::setupSprite(sf::Texture& t_gesier, sf::Texture& t_bubble)
{
	m_sprite.setTexture(t_gesier);
	m_sprite.setScale(0.2f, 0.2f);
	m_sprite.setPosition(m_position + m_spriteOffset);

	bubble.setupSprite(t_bubble);
}

sf::Sprite Geiser::getBubbleSprite()
{
	return bubble.getSprite();
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

void Geiser::enableBubble()
{
	bubble.spawn(m_position);
}
