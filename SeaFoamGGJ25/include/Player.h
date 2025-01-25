
#include "GameEntity.h"
class Player :
	public GameEntity
{
public:
	Player();
	void floatUp();
	void movementStop();
	void damaged(int t_damage);
	void healed(int t_heal);
	void stopped();

private:
	sf::Vector2f m_floatVelocity;
	int m_health;
};
