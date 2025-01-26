#pragma once
#include "GameEntity.h"
class PufferFish :
    public GameEntity
{
public:
    //sf::Vector2f t_upper = sf::Vector2f(600.0f, 600.0f), sf::Vector2f t_lower = sf::Vector2f(200.0f, 100.0f), 
    PufferFish(float t_speed = 2.0f);
    void move();
    void setupSprite(sf::Texture& t_puff, sf::Texture& t_eel);
    void setupPosition(sf::Vector2f t_upper, sf::Vector2f t_lower, sf::Vector2f t_pos, int t_direction);

private:
    sf::Vector2f m_upperLimit;
    sf::Vector2f m_lowerLimit;
    float m_speed;
    int m_direction;
};