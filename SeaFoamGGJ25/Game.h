/// <summary>
/// author Pete Lowe May 2022
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "menu.h"

enum class GameState {MENU, GAMEPLAY, CUTSCENE_START, CUTSCENE_END};

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void menuUpdate();
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_menuText; // Text used to denote the Menu
	sf::Text m_gameText; // Text used to denote the Game
	GameState m_state = GameState::MENU;
	bool m_exitGame; // control exiting game

	menu m_menu;
};

#endif // !GAME_HPP

