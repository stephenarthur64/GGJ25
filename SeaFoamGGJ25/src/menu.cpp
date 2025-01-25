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

void menu::initialise() {
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
}

void menu::render(sf::RenderWindow& t_window) {
	t_window.draw(m_introButton);
	t_window.draw(m_playButton);
	t_window.draw(m_quitButton);
}

void menu::update(sf::Time t_deltaTime) {

}