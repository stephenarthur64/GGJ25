#include "Collisions.h"

bool Collisions::checkCollideRect(sf::RectangleShape &t_player, sf::RectangleShape &t_object)
{
	return t_player.getGlobalBounds().intersects(t_object.getGlobalBounds());
}

bool Collisions::checkCollideCirc(sf::RectangleShape& t_player, sf::CircleShape& t_object)
{
	return t_player.getGlobalBounds().intersects(t_object.getGlobalBounds());
}
