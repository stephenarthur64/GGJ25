#include "GameEntity.h"

GameEntity::GameEntity() : m_velocity(sf::Vector2f(0.0f, 0.0f)), m_position(sf::Vector2f(40.0f, 300.0f)), m_spriteOffset(sf::Vector2f(0.0f, 0.0f))
{
}

void GameEntity::setupBody(sf::Color t_colour)
{
	m_body.setFillColor(t_colour);
	m_body.setSize(sf::Vector2f(60.0f, 90.0f));
	m_body.setPosition(m_position);
}

sf::RectangleShape GameEntity::getBody()
{
	return m_body;
}

sf::FloatRect GameEntity::getBounds()
{
	return m_body.getGlobalBounds();
}

sf::Sprite GameEntity::getSprite()
{
	return m_sprite;
}

void GameEntity::move(sf::Vector2f t_direction)
{
	m_velocity.y = 0.0f;
	m_velocity = t_direction;

	if (m_velocity.x < 0)
	{
		m_sprite.setScale(0.1f, 0.1f);
		m_sprite.setRotation(315);
	}
	else
	{
		m_sprite.setScale(-0.1f, 0.1f);
		m_sprite.setRotation(45);
	}
}

void GameEntity::updatePosition()
{
	m_position += m_velocity;
	m_body.setPosition(m_position);
	m_sprite.setPosition(m_position + m_spriteOffset);
}


