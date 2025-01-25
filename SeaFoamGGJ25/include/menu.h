#pragma once
#include <SFML/Graphics.hpp>

class menu {
	//Sprites and textures
	sf::Sprite m_menuBackgroundSprite;
	sf::Texture m_menuBackgroundTexture;

	//Location of where you clicked
	sf::Vector2f m_mouseEnd;


	//Buttons
	//Play button	
	sf::RectangleShape m_playButton;
	sf::Vector2f m_playButtonSize;
	sf::Vector2f m_playButtonPosition;

public:
	//Constructor
	menu();
	void initialise();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
};