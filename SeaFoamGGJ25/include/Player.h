
#include "GameEntity.h"
class Player :
	public GameEntity
{
public:
	Player();
	void setupSprite(sf::Texture& t_texture);
	void floatUp();
	void movementStop();
	void damaged(int t_damage);
	void healed(int t_heal);
	void stopped();
	void scrollPosition(int t_scrollingX, float t_viewY, sf::View &t_view);
	void die();
	bool isDead();
	sf::Vector2f getPosition() { return m_position; }
	void setPosition(sf::Vector2f t_pos) { m_position = t_pos; }

	int getHealth();
	

private:
	

	sf::Vector2f m_floatVelocity;
	int m_health;
	const int MAX_HEALTH = 3;
};
