#pragma once
#include "GameEntity.h"
class Spike :
    public GameEntity
{
public:
    Spike();
    void setupBody(int t_orientation, sf::Vector2f t_pos, sf::Vector2f t_size);
    void setupSprite(sf::Texture& t_texture);
private:
    int m_orientation;
    sf::Vector2f m_size;
};

