#pragma once
#include <SFML/Graphics.hpp>

class Collisions
{
public:
	static bool checkCollideRect(sf::RectangleShape& t_player, sf::RectangleShape& t_object);
	static bool checkCollideCirc(sf::RectangleShape& t_player, sf::CircleShape& t_object);
};

