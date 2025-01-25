#pragma once
#include <SFML/Graphics.hpp>

class menu {
	// Text used to denote the Menu
	sf::Text m_menuText;
	sf::Text m_introButtonText;
	sf::Text m_levelsButtonText;
	sf::Text m_quitButtonText;
	sf::Font m_ArialBlackfont; // font used by message

	//Sprites and textures
	sf::Sprite m_menuBackgroundSprite;
	sf::Texture m_menuBackgroundTexture;

	//Location of where you clicked
	sf::Vector2f m_mouseEnd;


	//Buttons
	//Intro button	
	sf::RectangleShape m_introButton;
	sf::Vector2f m_introButtonSize;
	sf::Vector2f m_introButtonPosition;
	//Play button	
	sf::RectangleShape m_playButton;
	sf::Vector2f m_playButtonSize;
	sf::Vector2f m_playButtonPosition;
	//Quit button	
	sf::RectangleShape m_quitButton;
	sf::Vector2f m_quitButtonSize;
	sf::Vector2f m_quitButtonPosition;

public:
	//Constructor
	menu();
	void initialise();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void setupFontAndText();
};