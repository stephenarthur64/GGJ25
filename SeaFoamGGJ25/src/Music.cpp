#include "music.h"
#include "Game.h"

void audio::loadFiles()
{
	if (!m_menuMusic.openFromFile("ASSETS\\MUSIC\\emmamenutheme.ogg"))
	{
		std::cout << "Error loading menu theme" << std::endl;
	}
	m_menuMusic.setLoop(true);
}

void audio::stopMusic(){
	m_menuMusic.stop();
}

void audio::playMenuTheme() {
	m_menuMusic.play();
}