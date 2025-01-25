#include <iostream>
#include "menu.h"

menu::menu() {
	//Intro button	
	m_introButtonSize = { 250,50 };
	m_introButtonPosition = { 978,436 };
	//Play button	
	m_playButtonSize = { 250,50 };
	m_playButtonPosition = { 978,526 };
	//Play button	
	m_quitButtonSize = { 250,50 };
	m_quitButtonPosition = { 978,616 };
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
	m_menuText.setFillColor(sf::Color::Black);

	m_introButtonText.setFont(m_ArialBlackfont);
	m_introButtonText.setString("Intro");
	m_introButtonText.setPosition(1067.0f, 445.0f);
	m_introButtonText.setCharacterSize(28U);
	m_introButtonText.setFillColor(sf::Color::Black);

	m_levelsButtonText.setFont(m_ArialBlackfont);
	m_levelsButtonText.setString("Levels");
	m_levelsButtonText.setPosition(1067.0f, 535.0f);
	m_levelsButtonText.setCharacterSize(28U);
	m_levelsButtonText.setFillColor(sf::Color::Black);

	m_quitButtonText.setFont(m_ArialBlackfont);
	m_quitButtonText.setString("Quit");
	m_quitButtonText.setPosition(1067.0f, 625.0f);
	m_quitButtonText.setCharacterSize(28U);
	m_quitButtonText.setFillColor(sf::Color::Black);

}

void menu::initialise() {

	setupFontAndText();
	//Intro button
	m_introButton.setSize(m_introButtonSize);
	m_introButton.setFillColor(sf::Color::Red);
	m_introButton.setPosition(m_introButtonPosition);
	//Play button
	m_playButton.setSize(m_playButtonSize);
	m_playButton.setFillColor(sf::Color::Red);
	m_playButton.setPosition(m_playButtonPosition);
	//Quit button	
	m_quitButton.setSize(m_quitButtonSize);
	m_quitButton.setFillColor(sf::Color::Red);
	m_quitButton.setPosition(m_quitButtonPosition);

	if (!m_menuBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu_background.png"))
	{
		std::cout << "Problem loading cube file" << std::endl;
	}
	m_menuBackgroundSprite.setTexture(m_menuBackgroundTexture);
}

void menu::render(sf::RenderWindow& t_window) {
	t_window.draw(m_menuBackgroundSprite);
	t_window.draw(m_introButton);
	t_window.draw(m_playButton);
	t_window.draw(m_quitButton);
	t_window.draw(m_menuText);
	t_window.draw(m_introButtonText);
	t_window.draw(m_levelsButtonText);
	t_window.draw(m_quitButtonText);
}

void menu::update(sf::Time t_deltaTime) {

}