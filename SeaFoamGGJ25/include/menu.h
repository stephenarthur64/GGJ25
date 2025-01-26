#pragma once
#include <SFML/Graphics.hpp>

class menu {
	//Main Menu
	// Text used to denote the Menu
	sf::Text m_menuText;
	sf::Text m_introButtonText;
	sf::Text m_levelsButtonText;
	sf::Text m_quitButtonText;
	sf::Font m_ArialBlackfont; // font used by message

	//Sprites and textures
	sf::Sprite m_menuBackgroundSprite;
	sf::Texture m_menuBackgroundTexture;

	sf::Sprite m_gameLogoSprite;
	sf::Texture m_gameLogoTexture;

	//Sprites and textures
	sf::Sprite m_levelMapSprite;
	sf::Texture m_levelMapTexture;

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

	//Level Menu
	bool levelMenu;

	sf::Text m_backButtonText;

	//Back button	
	sf::RectangleShape m_backButton;
	sf::Vector2f m_backButtonSize;
	sf::Vector2f m_backButtonPosition;
	//back button Hidden
	sf::RectangleShape m_backButtonHidden;
	sf::Vector2f m_backButtonHiddenSize;
	sf::Vector2f m_backButtonHiddenPosition;

	//Level screen level buttons
	//Level One button
	sf::Text m_levelOneButtonText;
	sf::Text m_levelTwoButtonText;
	//Clickable area
	sf::RectangleShape m_levelOneButton;
	sf::Vector2f m_levelOneButtonSize;
	sf::Vector2f m_levelOneButtonPosition;
	//Underline that points to map
	sf::RectangleShape m_levelOneUnderline;
	sf::Vector2f m_levelOneUnderlineSize;
	sf::Vector2f m_levelOneUnderlinePosition;
	//Circle for point
	sf::CircleShape m_levelOneCircle;
	sf::Vector2f m_levelOneCirclePosition;

	//Level Two button
	//Clickable area
	sf::RectangleShape m_levelTwoButton;
	sf::Vector2f m_levelTwoButtonSize;
	sf::Vector2f m_levelTwoButtonPosition;
	//Underline that points to map
	sf::RectangleShape m_levelTwoUnderline;
	sf::Vector2f m_levelTwoUnderlineSize;
	sf::Vector2f m_levelTwoUnderlinePosition;
	//Circle for point
	sf::CircleShape m_levelTwoCircle;
	sf::Vector2f m_levelTwoCirclePosition;


public:
	//Constructor
	menu();
	void initialise();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void setupFontAndText();
	void checkIfPressed(sf::Event t_newEvent, sf::RenderWindow &window);
};