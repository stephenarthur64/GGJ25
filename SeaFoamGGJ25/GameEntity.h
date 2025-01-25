#pragma once
#include <SFML/Graphics.hpp>

class GameEntity
{
public:
	void setupBody();

protected:
	sf::RectangleShape m_body;

};

