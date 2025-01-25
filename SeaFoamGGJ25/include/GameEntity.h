#pragma once
#include <SFML/Graphics.hpp>

class GameEntity {
public:
	GameEntity();
	void setupBody(sf::Color t_colour);
	sf::RectangleShape getBody();
	
	void move(sf::Vector2f t_direction);
	void updatePosition();


protected:
	sf::RectangleShape m_body;
	sf::Color m_colour;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};