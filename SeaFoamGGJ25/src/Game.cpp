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
	m_guiView(sf::FloatRect({ 0.0f, 0.0f }, { (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT })),
	m_menuView(sf::FloatRect({ 0.0f, 0.0f }, { (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT }))
{
	resetGame();
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	m_menu.initialise();
	levelOne();

	m_audio.loadFiles();
	m_audio.playMenuTheme();
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
	for (int i = 0; i < 5; i++)
	{
		puff[i].move();
		geiser[i].moveBubble();
	}
	checkCollisions();
	if (m_geiserFrames >= 300)
	{
		m_geiserFrames = 0;
		for (int i = 0; i < 5; i++)
		{
			geiser[i].enableBubble();
		}
	}

	m_geiserFrames++;

	if (player.getPosition().x >= 1000)
	{
		resetCamera();
		m_state = GameState::MENU;
	}
}

void Game::menuUpdate()
{
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.setView(m_menuView);
	m_window.clear(sf::Color::White);
	if (m_state == GameState::MENU)
	{
		m_menu.render(m_window);
	}
	if (m_state == GameState::GAMEPLAY)
	{
		m_window.setView(m_gameView);
		
		m_window.draw(m_background);
		//m_window.draw(m_gameText);
		//m_window.draw(player.getBody());
		m_window.draw(player.getSprite());
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Index: " << i << " X: " << puff[i].m_position.x << " Y: " << puff[i].m_position.y << std::endl;
			//m_window.draw(puff[i].getBody());
			m_window.draw(puff[i].getSprite());
			//m_window.draw(mite[i].getBody());
			m_window.draw(mite[i].getSprite());
			//m_window.draw(tite[i].getBody());
			m_window.draw(tite[i].getSprite());
			//m_window.draw(geiser[i].getBody());
			m_window.draw(geiser[i].getSprite());
			//m_window.draw(geiser[i].getBubble());
			m_window.draw(geiser[i].getBubbleSprite());
		}
		m_window.draw(puff[2].getBody());

		m_window.draw(borderTop.getBody());
		m_window.draw(borderBottom.getBody());
		m_window.setView(m_guiView); // All GUI drawn after this point <-------------
		m_window.draw(m_healthText);
	}
	m_window.display();
}

void Game::checkCollisions()
{
	for (int i = 0; i < 5; i++)
	{
		if (player.getBounds().intersects(puff[i].getBounds()))
		{
			player.damaged(1);
		}

		if (player.getBounds().intersects(mite[i].getBounds()))
		{
			player.damaged(2);
		}

		if (player.getBounds().intersects(tite[i].getBounds()))
		{
			player.damaged(2);
		}

		if (player.getBounds().intersects(geiser[i].getBubbleBounds()))
		{
			player.healed(1);
			geiser[i].disableBubble();
		}

		if (player.getBounds().intersects(geiser[i].getBounds()))
		{
			player.stopped();
		}
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
	puff[0].setupPosition(sf::Vector2f(600.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(300.0f, 300.0f), 1);
	puff[1].setupPosition(sf::Vector2f(600.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(500.0f, 300.0f), 1);
	puff[2].setupPosition(sf::Vector2f(600.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(600.0f, 200.0f), 1);
	puff[3].setupPosition(sf::Vector2f(600.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(300.0f, 600.0f), 1);
	puff[4].setupPosition(sf::Vector2f(600.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(300.0f, 500.0f), 1);

/*	puff[0].m_position = sf::Vector2f(300.0f, 300.0f);
	puff[1].m_position = sf::Vector2f(300.0f, 600.0f);
	puff[2].m_position = sf::Vector2f(500.0f, 300.0f);
	puff[3].m_position = sf::Vector2f(300.0f, 600.0f);
	puff[4].m_position = sf::Vector2f(300.0f, 500.0f);*/ 
}

void Game::levelOne()
{
	puff[0].setupPosition(sf::Vector2f(600.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(300.0f, 300.0f), 1);
	mite[0].setPosition({ 500.0f, 450.0f });
	tite[0].setPosition({ 600.0f, 250.0f });
	geiser[0].setPosition({ 800.0f, 500.0f });
	mite[1].setPosition({ 1000.0f, 450.0f });
	tite[1].setPosition({ 1100.0f, 250.0f });
	mite[2].setPosition({ 1200.0f, 450.0f });
	puff[1].setupPosition(sf::Vector2f(1600.0f, 0.0f), sf::Vector2f(1200.0f, 600.0f), sf::Vector2f(300.0f, 300.0f), 0);
	tite[2].setPosition({ 1600.0f, 0.0f });

	tite[2].setPosition({ 1600000.0f, 0.0f });
	tite[3].setPosition({ 1600000.0f, 0.0f });
	tite[4].setPosition({ 1600000.0f, 0.0f });
	mite[3].setPosition({ 1600000.0f, 0.0f });
	mite[4].setPosition({ 1600000.0f, 0.0f });
	puff[2].setupPosition(sf::Vector2f(1600.0f, 0.0f), sf::Vector2f(1200.0f, 600.0f), sf::Vector2f(1111300.0f, 300.0f), 0);
	puff[3].setupPosition(sf::Vector2f(1600.0f, 0.0f), sf::Vector2f(1200.0f, 600.0f), sf::Vector2f(1111300.0f, 300.0f), 0);
	puff[4].setupPosition(sf::Vector2f(1600.0f, 0.0f), sf::Vector2f(1200.0f, 600.0f), sf::Vector2f(1111300.0f, 300.0f), 0);
	geiser[1].setPosition({ 999800.0f, 600.0f });
	geiser[2].setPosition({ 999800.0f, 600.0f });
	geiser[3].setPosition({ 999800.0f, 600.0f });
	geiser[4].setPosition({ 999800.0f, 600.0f });
}

void Game::resetCamera()
{
	player.setPosition({ 0.0f, 0.0f });
	m_window.setView(m_menuView);
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
	for (int i = 0; i < 5; i++)
	{
		puff[i].setupBody(sf::Color::Red);
		mite[i].setupBody(0, sf::Vector2f(600.0f, 420.0f), sf::Vector2f(50.0f, 300.0f));
		tite[i].setupBody(1, sf::Vector2f(800.0f, 300.0f), sf::Vector2f(50.0f, 300.0f));
	}

	geiser[0].setupBody(sf::Vector2f(11111, 500.0f));
	geiser[1].setupBody(sf::Vector2f(111300.0f, 500.0f));
	geiser[2].setupBody(sf::Vector2f(411100.0f, 500.0f));
	geiser[3].setupBody(sf::Vector2f(5111100.0f, 500.0f));
	geiser[4].setupBody(sf::Vector2f(61100.0f, 500.0f));

	
	borderTop.setupBody(0);
	borderBottom.setupBody(1);

	if (m_backgroundTexture.loadFromFile("ASSETS/IMAGES/Environment/background.png"))
	{
		m_background.setTexture(m_backgroundTexture);
		m_background.setScale(0.5f, 0.5f);
	}

	if (m_playerTexture.loadFromFile("ASSETS/IMAGES/Player/Bubble 6.png"));
	{
		player.setupSprite(m_playerTexture);
	}

	if (m_puffTexture.loadFromFile("ASSETS/IMAGES/Enemies/Spike puffer 1.png") && m_eelTexture.loadFromFile("ASSETS/IMAGES/Enemies/Eel.png"))
	{
		for (int i = 0; i < 5; i++)
		{
			puff[i].setupSprite(m_puffTexture, m_eelTexture);
		}
	}
	
	if (m_spikeTexture.loadFromFile("ASSETS/IMAGES/Environment/stalactite.png"))
	{
		for (int i = 0; i < 5; i++)
		{
			mite[i].setupSprite(m_spikeTexture);
			tite[i].setupSprite(m_spikeTexture);
		}
	}

	if (m_bubbleTexture.loadFromFile("ASSETS/IMAGES/Environment/Bubble.png") && m_geiserTexture.loadFromFile("ASSETS/IMAGES/Environment/Geezer.png"))
	{
		for (int i = 0; i < 5; i++)
		{
			geiser[i].setupSprite(m_geiserTexture, m_bubbleTexture);
		}
	}

}
