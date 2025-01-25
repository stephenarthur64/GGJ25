#include "Collisions.h"

static bool Collisions::checkCollideRect(sf::RectangleShape& t_player, sf::RectangleShape& t_object)
{
	if (t_player.getGlobalBounds().intersects(t_object.getGlobalBounds()))
	{
		player.damaged(1);
		return true;
	}

	return false;
}

static bool Collisions::checkCollideCirc(sf::RectangleShape& t_player, sf::CircleShape& t_object)
{
	return t_player.getGlobalBounds().intersects(t_object.getGlobalBounds());
}

