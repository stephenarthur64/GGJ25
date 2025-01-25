#pragma once
#include <SFML/Graphics.hpp>

class GameEntity {
public:
	GameEntity();
	void setupBody();
	sf::RectangleShape getBody();
	
	void move(sf::Vector2f t_direction);


protected:
	sf::RectangleShape m_body;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

};