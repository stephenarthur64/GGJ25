
#include "GameEntity.h"
class Player :
	public GameEntity
{
public:
	Player();
	void floatUp();
	void movementStop();

private:
	sf::Vector2f m_floatVelocity;
	int m_health;
};
