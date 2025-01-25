#include "GameEntity.h"

GameEntity::GameEntity() : m_velocity(sf::Vector2f(0.0f, 0.0f)), m_position(sf::Vector2f(40.0f, 300.0f))
							
{
}

void GameEntity::setupBody()
{
	m_body.setFillColor(sf::Color::Blue);
	m_body.setSize(sf::Vector2f(60.0f, 60.0f));
	m_body.setPosition(m_position);
}

sf::RectangleShape GameEntity::getBody()
{
	return m_body;
}

void GameEntity::move(sf::Vector2f t_direction)
{
	m_velocity = t_direction;
	m_position += m_velocity;
	m_body.setPosition(m_position);
}


