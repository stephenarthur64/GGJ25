#include "PufferFish.h"

PufferFish::PufferFish(float t_speed) : m_speed(t_speed)
{
	m_spriteOffset = sf::Vector2f(130.0f, 180.0f);
}

void PufferFish::move()
{
	if (m_direction == 0)
	{
		m_velocity = sf::Vector2f(m_speed, 0.0f);
		if (m_position.x >= m_upperLimit.x)
		{
			m_speed = -2.0f;
			m_velocity.x = m_speed;
		}
		if (m_position.x <= m_lowerLimit.x)
		{
			m_speed = 2.0f;
			m_velocity.x = m_speed;
		}
	}

	if (m_direction == 1)
	{
		m_velocity = sf::Vector2f(0.0f, m_speed);
		if (m_position.y >= m_upperLimit.y)
		{
			m_speed = -2.0f;
			m_velocity.y += m_speed;
		}
		if (m_position.y <= m_lowerLimit.y)
		{
			m_speed = 2.0f;
			m_velocity.y += m_speed;
		}
	}

	m_position += m_velocity;
	m_body.setPosition(m_position);
	m_sprite.setPosition(m_position + m_spriteOffset);
}

void PufferFish::setupSprite(sf::Texture& t_puff, sf::Texture &t_eel)
{
	m_sprite.setTexture(t_puff);
	m_sprite.setScale(0.3f, 0.3f);
	m_sprite.setOrigin(590.0f, 820.0f);
	m_sprite.setTextureRect(sf::IntRect(340, 450, 559, 635));
	m_sprite.setPosition(m_position + m_spriteOffset);
}

void PufferFish::setupPosition(sf::Vector2f t_upper, sf::Vector2f t_lower, sf::Vector2f t_pos, int t_direction)
{
	m_upperLimit = t_upper;
	m_lowerLimit = t_lower;
	m_direction = t_direction;
	m_position = t_pos;
}
