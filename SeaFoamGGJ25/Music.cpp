#include "music.h"
#include "Game.h"

void Music::loadFiles()
{
	if (!m_menuMusic.openFromFile("ASSETS\\AUDIO\\emmamenutheme.wav"))
	{
		std::cout << "Error loading menu theme" << std::endl;
	}
	m_menuMusic.setLoop(true);
}

void Music::stopMusic(){
	m_menuMusic.stop();
}
