#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Music
{
private:
	sf::Music m_menuMusic;
	void loadFiles();
	void stopMusic();
};