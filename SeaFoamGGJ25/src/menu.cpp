#include "menu.h"

menu::menu() {
	//Play button	
	m_playButtonSize = { 50,50 };
	m_playButtonPosition = { 100,100 };
}

void menu::initialise() {
	m_playButton.setSize(m_playButtonSize);
	m_playButton.setFillColor(sf::Color::Red);
	m_playButton.setPosition(m_playButtonPosition);
}

void menu::render(sf::RenderWindow& t_window) {
	t_window.draw(m_playButton);
}

void menu::update(sf::Time t_deltaTime) {

}