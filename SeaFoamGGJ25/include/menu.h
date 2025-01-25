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
	//Intro button Hidden
	sf::RectangleShape m_introButtonHidden;
	sf::Vector2f m_introButtonHiddenSize;
	sf::Vector2f m_introButtonHiddenPosition;
	//Levels button	
	sf::RectangleShape m_levelsButton;
	sf::Vector2f m_levelsButtonSize;
	sf::Vector2f m_levelsButtonPosition;
	//Levels button	hidden
	sf::RectangleShape m_levelsButtonHidden;
	sf::Vector2f m_levelsButtonHiddenSize;
	sf::Vector2f m_levelsButtonHiddenPosition;
	//Quit button	
	sf::RectangleShape m_quitButton;
	sf::Vector2f m_quitButtonSize;
	sf::Vector2f m_quitButtonPosition;
	//Quit button Hidden
	sf::RectangleShape m_quitButtonHidden;
	sf::Vector2f m_quitButtonHiddenSize;
	sf::Vector2f m_quitButtonHiddenPosition;

	sf::RectangleShape m_backgroundOpaic;
	sf::Vector2f m_backgroundOpaicSize;
	sf::Vector2f m_backgroundOpaicPosition;

	bool levelMenu;

public:
	//Constructor
	menu();
	void initialise();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void setupFontAndText();
	void checkIfPressed(sf::Event t_newEvent);
};