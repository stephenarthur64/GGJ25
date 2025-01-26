#include <iostream>
#include "menu.h"

menu::menu() {
	levelMenu = false;
	introActive = false;
	cutscene_index = 0;

	//Intro button	
	m_introButtonSize = { 260,5 };
	m_introButtonPosition = { 525,505 };
	//Intro button Hidden
	m_introButtonHiddenSize = { 260,60 };
	m_introButtonHiddenPosition = { 525,435 };
	//Levels button	
	m_levelsButtonSize = { 260,5 };
	m_levelsButtonPosition = { 525,595 };
	//Levels button	Hidden
	m_levelsButtonHiddenSize = { 260,60 };
	m_levelsButtonHiddenPosition = { 525,545 };
	//Quit button	
	m_quitButtonSize = { 260,5 };
	m_quitButtonPosition = { 525,685 };
	//Quit button Hidden
	m_quitButtonHiddenSize = { 260,60 };
	m_quitButtonHiddenPosition = { 525,635 };

	//Background opaic
	m_backgroundOpaicSize = { 800, 720 };
	m_backgroundOpaicPosition = { 900, 0 };

	//Level Screen
	//Back button	
	m_backButtonSize = { 260,5 };
	m_backButtonPosition = { 972,665 };
	//Back button Hidden
	m_backButtonHiddenSize = { 260,60 };
	m_backButtonHiddenPosition = { 972,615 };
	

	//Level buttons
	//Clickable area
	m_levelOneButtonSize = { 459, 67 };
	m_levelOneButtonPosition = { 780, 460 };
	//Underline
	m_levelOneUnderlineSize = { 749, 5 };
	m_levelOneUnderlinePosition = { 490, 527 };
	//Circle for point
	m_levelOneCirclePosition = { 450, 505 };

	//Level Two button
	//Clickable area
	m_levelTwoButtonSize = { 459, 67 };
	m_levelTwoButtonPosition = { 780, 207 };
	//Underline that points to map
	m_levelTwoUnderlineSize = { 749, 5 };
	m_levelTwoUnderlinePosition = { 490, 274 };
	//Circle for point
	m_levelTwoCirclePosition = { 450, 251 };
}

void menu::setupFontAndText() {
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\Bubble3D.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_menuText.setFont(m_ArialBlackfont);
	m_menuText.setString("Sea Foam");
	m_menuText.setPosition(556.0f, 142.0f);
	m_menuText.setCharacterSize(128U);
	m_menuText.setFillColor(sf::Color::White);

	m_introButtonText.setFont(m_ArialBlackfont);
	m_introButtonText.setString("Intro");
	m_introButtonText.setPosition(576.0f, 445.0f);
	m_introButtonText.setCharacterSize(50U);
	m_introButtonText.setFillColor(sf::Color::White);

	m_levelsButtonText.setFont(m_ArialBlackfont);
	m_levelsButtonText.setString("Levels");
	m_levelsButtonText.setPosition(566.0f, 535.0f);
	m_levelsButtonText.setCharacterSize(50U);
	m_levelsButtonText.setFillColor(sf::Color::White);

	m_quitButtonText.setFont(m_ArialBlackfont);
	m_quitButtonText.setString("Quit");
	m_quitButtonText.setPosition(586.0f, 625.0f);
	m_quitButtonText.setCharacterSize(50U);
	m_quitButtonText.setFillColor(sf::Color::White);

	m_backButtonText.setFont(m_ArialBlackfont);
	m_backButtonText.setString("Back");
	m_backButtonText.setPosition(1037.0f, 605.0f);
	m_backButtonText.setCharacterSize(50U);
	m_backButtonText.setFillColor(sf::Color::White);

	m_levelOneButtonText.setFont(m_ArialBlackfont);
	m_levelOneButtonText.setString("Level One");
	m_levelOneButtonText.setPosition(900.0f, 465.0f);
	m_levelOneButtonText.setCharacterSize(48U);
	m_levelOneButtonText.setFillColor(sf::Color::White);

	m_levelTwoButtonText.setFont(m_ArialBlackfont);
	m_levelTwoButtonText.setString("Level Two");
	m_levelTwoButtonText.setPosition(900.0f, 210.0f);
	m_levelTwoButtonText.setCharacterSize(48U);
	m_levelTwoButtonText.setFillColor(sf::Color::White);

	m_introCutsceneText.setFont(m_ArialBlackfont);
	m_introCutsceneText.setString("Test");
	m_introCutsceneText.setPosition(290.0f, 190.0f);
	m_introCutsceneText.setCharacterSize(48U);
	m_introCutsceneText.setFillColor(sf::Color(211,210,213,255));
	m_introCutsceneText.setOutlineColor(sf::Color::Black);
	m_introCutsceneText.setOutlineThickness(2);

}

void menu::initialise() {

	setupFontAndText();
	//Intro button
	m_introButton.setSize(m_introButtonSize);
	m_introButton.setFillColor(sf::Color::White);
	m_introButton.setPosition(m_introButtonPosition);
	//Intro button Hidden
	m_introButtonHidden.setSize(m_introButtonHiddenSize);
	m_introButtonHidden.setFillColor(sf::Color::White);
	m_introButtonHidden.setPosition(m_introButtonHiddenPosition);
	//Levels button
	m_levelsButton.setSize(m_levelsButtonSize);
	m_levelsButton.setFillColor(sf::Color::White);
	m_levelsButton.setPosition(m_levelsButtonPosition);
	//Levels hidden button
	m_levelsButtonHidden.setSize(m_levelsButtonHiddenSize);
	m_levelsButtonHidden.setPosition(m_levelsButtonHiddenPosition);
	//Quit button	
	m_quitButton.setSize(m_quitButtonSize);
	m_quitButton.setFillColor(sf::Color::White);
	m_quitButton.setPosition(m_quitButtonPosition);
	//Quit button	
	m_quitButtonHidden.setSize(m_quitButtonHiddenSize);
	m_quitButtonHidden.setFillColor(sf::Color::White);
	m_quitButtonHidden.setPosition(m_quitButtonHiddenPosition);

	//Background Opaic
	m_backgroundOpaic.setSize(m_backgroundOpaicSize);
	m_backgroundOpaic.setFillColor(sf::Color(0,0,0,100));
	m_backgroundOpaic.setPosition(m_backgroundOpaicPosition);


	//Level Screen
	//Back button	
	m_backButton.setSize(m_backButtonSize);
	m_backButton.setFillColor(sf::Color::White);
	m_backButton.setPosition(m_backButtonPosition);
	//Back button	
	m_backButtonHidden.setSize(m_backButtonHiddenSize);
	m_backButtonHidden.setFillColor(sf::Color::White);
	m_backButtonHidden.setPosition(m_backButtonHiddenPosition);

	//Level buttons
	m_levelOneButton.setSize(m_levelOneButtonSize);
	m_levelOneButton.setFillColor(sf::Color(67, 94, 193, 255));
	m_levelOneButton.setPosition(m_levelOneButtonPosition);
	//Underline that points to map
	m_levelOneUnderline.setSize(m_levelOneUnderlineSize);
	m_levelOneUnderline.setFillColor(sf::Color::White);
	m_levelOneUnderline.setPosition(m_levelOneUnderlinePosition);
	//Circle for point
	m_levelOneCircle.setRadius(25);
	m_levelOneCircle.setFillColor(sf::Color::Red);
	m_levelOneCircle.setPosition(m_levelOneCirclePosition);

	//Level buttons Two
	m_levelTwoButton.setSize(m_levelTwoButtonSize);
	m_levelTwoButton.setFillColor(sf::Color(67, 94, 193, 255));
	m_levelTwoButton.setPosition(m_levelTwoButtonPosition);
	//Underline that points to map
	m_levelTwoUnderline.setSize(m_levelTwoUnderlineSize);
	m_levelTwoUnderline.setFillColor(sf::Color::White);
	m_levelTwoUnderline.setPosition(m_levelTwoUnderlinePosition);
	//Circle for point
	m_levelTwoCircle.setRadius(25);
	m_levelTwoCircle.setFillColor(sf::Color::Red);
	m_levelTwoCircle.setPosition(m_levelTwoCirclePosition);



	if (!m_menuBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\Menu\\menu_background.png"))
	{
		std::cout << "Problem loading main menu background file" << std::endl;
	}
	m_menuBackgroundSprite.setTexture(m_menuBackgroundTexture);
	if (!m_introBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\Menu\\intro_background.png"))
	{
		std::cout << "Problem loading main menu background file" << std::endl;
	}
	m_introBackgroundSprite.setTexture(m_introBackgroundTexture);
	m_introBackgroundSprite.setPosition(0, 0);
	if (!m_levelMapTexture.loadFromFile("ASSETS\\IMAGES\\Menu\\levelMap.png"))
	{
		std::cout << "Problem loading intro background background file" << std::endl;
	}
	m_levelMapSprite.setTexture(m_levelMapTexture);
	m_levelMapSprite.setPosition(49, 0);
	//Logo
	if (!m_gameLogoTexture.loadFromFile("ASSETS\\IMAGES\\Menu\\game_logo.png"))
	{
		std::cout << "Problem loading game logo file" << std::endl;
	}
	m_gameLogoSprite.setTexture(m_gameLogoTexture);
	m_gameLogoSprite.setPosition(300, -80);
	//m_gameLogoSprite.setPosition(-40, 340);
	m_gameLogoSprite.setScale(0.9f, 0.9f);
}

void menu::render(sf::RenderWindow& t_window) {
	if (introActive) {
		t_window.draw(m_introBackgroundSprite);
		t_window.draw(m_introCutsceneText);
	}
	else if (levelMenu == false) {
		t_window.draw(m_menuBackgroundSprite);
		//t_window.draw(m_backgroundOpaic);
		t_window.draw(m_gameLogoSprite);
		t_window.draw(m_introButton);
		t_window.draw(m_levelsButton);
		t_window.draw(m_quitButton);
		t_window.draw(m_introButtonText);
		t_window.draw(m_levelsButtonText);
		t_window.draw(m_quitButtonText);
	}
	else {
		t_window.draw(m_menuBackgroundSprite);
		t_window.draw(m_levelMapSprite);
		t_window.draw(m_backButton);
		t_window.draw(m_backButtonText);
		t_window.draw(m_levelOneButton);
		t_window.draw(m_levelOneUnderline);
		t_window.draw(m_levelOneCircle);
		t_window.draw(m_levelOneButtonText);
		t_window.draw(m_levelTwoButton);
		t_window.draw(m_levelTwoUnderline);
		t_window.draw(m_levelTwoCircle);
		t_window.draw(m_levelTwoButtonText);
	}
}

void menu::update(sf::Time t_deltaTime) {

}

void menu::checkIfPressed(sf::Event t_newEvent, sf::RenderWindow &window)
{
		m_mouseEnd.x = static_cast<float>(t_newEvent.mouseButton.x);
		m_mouseEnd.y = static_cast<float>(t_newEvent.mouseButton.y);
	if (introActive) {
		sf::FloatRect introBackgroundZone = m_introBackgroundSprite.getGlobalBounds();
		if (introBackgroundZone.contains(m_mouseEnd)) {
			cutscene_index++;
			switch (cutscene_index) {
				case 0:
					m_introCutsceneText.setString("There once was a god\n\nwho was once praised\n\nand worshiped by\n\nthe people.");
					break;
				case 1:
					m_introCutsceneText.setString("They asked for health\n\nand wellness,\n\nand he gave with\n\ntheir sacrifice.");
					break;
				case 2:
					m_introCutsceneText.setString("But he was\n\nan angry god. ");
					break;
				case 3:
					m_introCutsceneText.setString("One day a Sea Witch\n\narrived to the people\n\nbearing knowledge\n\nand potions...\n\n");
					break;
				case 4:
					m_introCutsceneText.setString("...to heal and help\n\nwithout need for\n\npray and sacrifice.");
					break;
				case 5:
					m_introCutsceneText.setString("The god was enraged\n\nat her for what\n\nshe had done");
					break;
				case 6:
					m_introCutsceneText.setString("he said he would\n\ndrown the people\n\nfor their disloyalty.  ");
					break;
				case 7:
					m_introCutsceneText.setString("The god punished\n\nthe Sea Witch for\n\nwhat she had done");
					break;
				case 8:
					m_introCutsceneText.setString("Casting her down\n\nto drown in\n\nthe sea caves.");
					break;
				case 9:
					m_introCutsceneText.setString("When the waters rose,\n\nshe used her last energy\n\nto create a\n\nBubble Familiar...");
					break;
				case 10:
					m_introCutsceneText.setString("...to transport a rune\n\nthat would create\n\na safety bubble of\n\nprotection from the god. ");
					break;
				case 11:
					m_introCutsceneText.setString("You can do this,\n\nsave them!");
					break;
				default:
					introActive = false;
					break;
			}
		}
	}
	else if (levelMenu == false){
		sf::FloatRect introButtonZone = m_introButtonHidden.getGlobalBounds();
		sf::FloatRect levelsButtonZone = m_levelsButtonHidden.getGlobalBounds();
		sf::FloatRect quitButtonZone = m_quitButtonHidden.getGlobalBounds();

		if (introButtonZone.contains(m_mouseEnd)) {
			introActive = true;
			cutscene_index = 0;
			m_introCutsceneText.setString("There once was a god\n\nwho was once praised\n\nand worshiped by\n\nthe people.");
		}
		if (levelsButtonZone.contains(m_mouseEnd)) {
			levelMenu = true;
		}
		if (quitButtonZone.contains(m_mouseEnd)) {
			window.close();
		}
	}
	else {
		sf::FloatRect backButtonZone = m_backButtonHidden.getGlobalBounds();
		sf::FloatRect levelOneButtonZone = m_levelOneButton.getGlobalBounds();
		sf::FloatRect levelTwoButtonZone = m_levelTwoButton.getGlobalBounds();
		if (backButtonZone.contains(m_mouseEnd)) {
			levelMenu = false;
		}
		if (levelOneButtonZone.contains(m_mouseEnd)) {
			std::cout << "Level One start" << std::endl;
			m_state = GameState::GAMEPLAY;
		}
		if (levelTwoButtonZone.contains(m_mouseEnd)) {
			std::cout << "Level Two start" << std::endl;
		}
	}
}