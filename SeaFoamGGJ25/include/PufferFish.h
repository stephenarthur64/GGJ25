#pragma once
#include "GameEntity.h"
class PufferFish :
    public GameEntity
{
public:
    PufferFish(sf::Vector2f t_upper = sf::Vector2f(600.0f, 600.0f), sf::Vector2f t_lower = sf::Vector2f(200.0f, 100.0f), float t_speed = 2.0f, int t_direction = 1);
    void move();
    void setupSprite(sf::Texture& t_texture);

private:
    sf::Vector2f m_upperLimit;
    sf::Vector2f m_lowerLimit;
    float m_speed;
    int m_direction;
};