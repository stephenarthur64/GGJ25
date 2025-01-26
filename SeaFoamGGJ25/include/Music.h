#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class audio
{
public:
	sf::Music m_menuMusic;
	void loadFiles();
	void stopMusic();
	void playMenuTheme();
};