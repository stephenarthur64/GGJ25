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
#include "GameEntity.h"
#include "Player.h"
#include "PufferFish.h"
#include "menu.h"
#include "Spike.h"
#include "Geiser.h"
#include "Collision.h"
#include "ScreenBorder.h"

enum class GameState { MENU, GAMEPLAY, CUTSCENE_START, CUTSCENE_END };

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
	void gameKeys(sf::Event& t_event);
	void update(sf::Time t_deltaTime);
	void entityUpdate(sf::Time t_deltaTime);
	void menuUpdate();
	void render();
	void checkCollisions();
	void updateCamera();
	void updateText();
	void resetGame();
	void levelOne();
	void resetCamera();
	
	void setupFontAndText();
	void setupSprite();

	const unsigned int SCREEN_WIDTH = 1280;
	const unsigned int SCREEN_HEIGHT = 720;
	int m_geiserFrames = 0;

	sf::RenderWindow m_window; // main SFML window
	sf::View m_gameView; // View for the game
	sf::View m_guiView; // View for gui
	sf::Font m_ArialBlackfont; // font used by message	sf::Text m_menuText; // Text used to denote the Menu
	sf::Text m_healthText;
	sf::Text m_gameText; // Text used to denote the Game
	GameState m_state = GameState::GAMEPLAY;
	Player player;
	PufferFish puff[5];
	Spike mite[5];
	Spike tite[5];
	Geiser geiser[5];
	sf::Sprite m_background;
	sf::Texture m_backgroundTexture;
	sf::Texture m_playerTexture;
	sf::Texture m_puffTexture;
	sf::Texture m_eelTexture;
	sf::Texture m_spikeTexture;
	sf::Texture m_geiserTexture;
	sf::Texture m_bubbleTexture;
	ScreenBorder borderTop;
	ScreenBorder borderBottom;
	bool m_exitGame; // control exiting game

	menu m_menu;
};

#endif // !GAME_HPP

