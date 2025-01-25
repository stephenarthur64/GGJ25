#include "ScreenBorder.h"

void ScreenBorder::setupBody(int type)
{
	m_body.setFillColor(sf::Color::Black);
	m_body.setSize(sf::Vector2f(1280.0f, 100.0f));

	if (type == 0)
	{
		m_body.setPosition(sf::Vector2f(0.0f, 0.0f));
	}

	if (type == 1)
	{
		m_body.setPosition(sf::Vector2f(0.0f, 620.0f));
	}
}
