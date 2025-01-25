#include <iostream>
#include "menu.h"

menu::menu() {
	levelMenu = false;

	//Intro button	
	m_introButtonSize = { 260,5 };
	m_introButtonPosition = { 972,490 };
	//Intro button Hidden
	m_introButtonHiddenSize = { 260,60 };
	m_introButtonHiddenPosition = { 972,430 };
	//Levels button	
	m_levelsButtonSize = { 260,5 };
	m_levelsButtonPosition = { 972,575 };
	//Levels button	Hidden
	m_levelsButtonHiddenSize = { 260,60 };
	m_levelsButtonHiddenPosition = { 972,525 };
	//Quit button	
	m_quitButtonSize = { 260,5 };
	m_quitButtonPosition = { 972,665 };
	//Quit button Hidden
	m_quitButtonHiddenSize = { 260,60 };
	m_quitButtonHiddenPosition = { 972,615 };

	//Background opaic
	m_backgroundOpaicSize = { 800, 720 };
	m_backgroundOpaicPosition = { 500, 0 };

	//Level Screen
	//Back button	
	m_backButtonSize = { 260,5 };
	m_backButtonPosition = { 972,665 };
	//Back button Hidden
	m_backButtonHiddenSize = { 260,60 };
	m_backButtonHiddenPosition = { 972,615 };

}

void menu::setupFontAndText() {
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
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
	m_introButtonText.setPosition(1067.0f, 445.0f);
	m_introButtonText.setCharacterSize(28U);
	m_introButtonText.setFillColor(sf::Color::White);

	m_levelsButtonText.setFont(m_ArialBlackfont);
	m_levelsButtonText.setString("Levels");
	m_levelsButtonText.setPosition(1058.0f, 535.0f);
	m_levelsButtonText.setCharacterSize(28U);
	m_levelsButtonText.setFillColor(sf::Color::White);

	m_quitButtonText.setFont(m_ArialBlackfont);
	m_quitButtonText.setString("Quit");
	m_quitButtonText.setPosition(1067.0f, 625.0f);
	m_quitButtonText.setCharacterSize(28U);
	m_quitButtonText.setFillColor(sf::Color::White);

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


	if (!m_menuBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu_background.png"))
	{
		std::cout << "Problem loading cube file" << std::endl;
	}
	m_menuBackgroundSprite.setTexture(m_menuBackgroundTexture);
}

void menu::render(sf::RenderWindow& t_window) {
	if (levelMenu == false) {
		t_window.draw(m_menuBackgroundSprite);
		t_window.draw(m_backgroundOpaic);
		t_window.draw(m_introButton);
		t_window.draw(m_levelsButton);
		t_window.draw(m_quitButton);
		t_window.draw(m_menuText);
		t_window.draw(m_introButtonText);
		t_window.draw(m_levelsButtonText);
		t_window.draw(m_quitButtonText);
	}
	else {
		t_window.draw(m_menuBackgroundSprite);
		t_window.draw(m_backButton);
	}
}

void menu::update(sf::Time t_deltaTime) {

}

void menu::checkIfPressed(sf::Event t_newEvent)
{
	if (levelMenu == false){
		m_mouseEnd.x = static_cast<float>(t_newEvent.mouseButton.x);
		m_mouseEnd.y = static_cast<float>(t_newEvent.mouseButton.y);
		sf::FloatRect introButtonZone = m_introButtonHidden.getGlobalBounds();
		sf::FloatRect levelsButtonZone = m_levelsButtonHidden.getGlobalBounds();
		sf::FloatRect quitButtonZone = m_quitButtonHidden.getGlobalBounds();

		if (introButtonZone.contains(m_mouseEnd)) {
			std::cout << "Intro Button" << std::endl;
		}
		if (levelsButtonZone.contains(m_mouseEnd)) {
			levelMenu = true;
		}
		if (quitButtonZone.contains(m_mouseEnd)) {
			std::cout << "Quit Button" << std::endl;
		}
	}
	else {

	}
}