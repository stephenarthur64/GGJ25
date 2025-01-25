/// <summary>
/// author Pete Lowe May 2022
/// you need to change the above line or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture

	m_menu.initialise();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
#ifdef _DEBUG
			render(); // want to debug drawing while stepping through code
#endif // _DEBUG

		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (newEvent.type == sf::Event::KeyReleased)
		{
			player.movementStop();
			player.floatUp();
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	if (m_state == GameState::MENU && sf::Keyboard::Space == t_event.key.code)
	{
		m_state = GameState::GAMEPLAY;
	}
	if (m_state == GameState::GAMEPLAY)
	{
		gameKeys(t_event);
	}
}

void Game::gameKeys(sf::Event &t_event)
{
	if (sf::Keyboard::D == t_event.key.code || sf::Keyboard::Right == t_event.key.code)
	{
		player.move(sf::Vector2f(5.0f, 0.0f));
	}
	else if (sf::Keyboard::A == t_event.key.code || sf::Keyboard::Left == t_event.key.code)
	{
		player.move(sf::Vector2f(-5.0f, 0.0f));
	}
	else if (sf::Keyboard::S == t_event.key.code || sf::Keyboard::Down == t_event.key.code)
	{
		player.move(sf::Vector2f(0.0f, 5.0f));
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (t_deltaTime.asMilliseconds() != 16)
	{
		std::cout << "time warp" << std::endl; // expecting 60 fps of action
	}

	switch (m_state)
	{
	case GameState::MENU:
		m_menu.update(t_deltaTime);
		break;
	case GameState::GAMEPLAY:
		entityUpdate(t_deltaTime);
		break;
	case GameState::CUTSCENE_START:
		break;
	case GameState::CUTSCENE_END:
		break;
	default:
		break;
	}

	if (m_exitGame)
	{
		m_window.close();
	}
}

void Game::entityUpdate(sf::Time t_deltaTime)
{
	player.updatePosition();
}

void Game::menuUpdate()
{
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	if (m_state == GameState::MENU)
	{
		m_menu.render(m_window);
	}
	if (m_state == GameState::GAMEPLAY)
	{
		m_window.draw(m_gameText);
		m_window.draw(player.getBody());
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_menuText.setFont(m_ArialBlackfont);
	m_menuText.setString("Menu State");
	m_menuText.setPosition(200.0f, 200.0f);
	m_menuText.setCharacterSize(80U);
	m_menuText.setFillColor(sf::Color::Red);
	m_menuText.setOutlineColor(sf::Color::Black);
	m_menuText.setOutlineThickness(3.0f);

	m_gameText.setFont(m_ArialBlackfont);
	m_gameText.setString("Game State");
	m_gameText.setPosition(200.0f, 200.0f);
	m_gameText.setCharacterSize(80U);
	m_gameText.setFillColor(sf::Color::Red);
	m_gameText.setOutlineColor(sf::Color::Black);
	m_gameText.setOutlineThickness(3.0f);
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	player.setupBody();
}
