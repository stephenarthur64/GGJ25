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
	m_exitGame{false}, //when true game will exit
	m_gameView(sf::FloatRect({ 0.0f, 0.0f}, {(float)SCREEN_WIDTH, (float)SCREEN_HEIGHT})),
	m_guiView(sf::FloatRect({ 0.0f, 0.0f }, { (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT }))
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
		if (sf::Event::Closed == newEvent.type) // window message
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
		if (m_state == GameState::MENU && newEvent.type == sf::Event::MouseButtonReleased) {
			m_menu.checkIfPressed(newEvent, m_window);
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

void Game::gameKeys(sf::Event& t_event)
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
		updateCamera();
		updateText();
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
	puff.move();
	geiser.moveBubble();
	checkCollisions();
}

void Game::menuUpdate()
{
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.setView(m_gameView);
	m_window.clear(sf::Color::White);
	if (m_state == GameState::MENU)
	{
		m_menu.render(m_window);
	}
	if (m_state == GameState::GAMEPLAY)
	{
		m_window.draw(m_gameText);
		m_window.draw(player.getBody());
		m_window.draw(puff.getBody());
		m_window.draw(mite.getBody());
		m_window.draw(tite.getBody());
		m_window.draw(geiser.getBody());
		m_window.draw(geiser.getBubble());
		m_window.draw(borderTop.getBody());
		m_window.draw(borderBottom.getBody());
		m_window.setView(m_guiView); // All GUI drawn after this point <-------------
		m_window.draw(m_healthText);
	}
	m_window.display();
}

void Game::checkCollisions()
{
	if (player.getBounds().intersects(puff.getBounds()))
	{
		player.damaged(1);
	}

	if (player.getBounds().intersects(mite.getBounds()))
	{
		player.damaged(2);
	}

	if (player.getBounds().intersects(tite.getBounds()))
	{
		player.damaged(2);
	}

	if (player.getBounds().intersects(geiser.getBubbleBounds()))
	{
		player.healed(1);
		geiser.disableBubble();
	}

	if (player.getBounds().intersects(geiser.getBounds()))
	{
		player.stopped();
	}

	if (player.getBounds().intersects(borderTop.getBounds()) || player.getBounds().intersects(borderBottom.getBounds()))
	{
		player.damaged(1);
	}
}

void Game::updateCamera()
{
	player.scrollPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, m_gameView);
	m_window.setView(m_gameView);
}

void Game::updateText()
{
	m_healthText.setString("Health: " + std::to_string(player.getHealth()));
}

void Game::resetGame()
{
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

	m_gameText.setFont(m_ArialBlackfont);
	m_gameText.setString("Game State");
	m_gameText.setPosition(200.0f, 200.0f);
	m_gameText.setCharacterSize(80U);
	m_gameText.setFillColor(sf::Color::Red);
	m_gameText.setOutlineColor(sf::Color::Black);
	m_gameText.setOutlineThickness(3.0f);

	m_healthText.setFont(m_ArialBlackfont);
	m_healthText.setString("Health: " + std::to_string(player.getHealth()));
	m_healthText.setPosition(0.0f, 660.0f);
	m_healthText.setCharacterSize(40U);
	m_healthText.setFillColor(sf::Color::Red);
	m_healthText.setOutlineColor(sf::Color::Black);
	m_healthText.setOutlineThickness(3.0f);
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	player.setupBody(sf::Color::Blue);
	puff.setupBody(sf::Color::Red);
	mite.setupBody(0, sf::Vector2f(600.0f, 420.0f), sf::Vector2f(50.0f, 300.0f));
	tite.setupBody(1, sf::Vector2f(800.0f, 300.0f), sf::Vector2f(50.0f, 300.0f));
	geiser.setupBody(sf::Vector2f(300.0f, 600.0f));
	borderTop.setupBody(0);
	borderBottom.setupBody(1);
}
