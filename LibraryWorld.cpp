#include "LibraryWorld.h"
#include "PlatformHelper.h"
#include "main.h"
#include "helper.h"
#include <stdio.h>

LibraryWorld::LibraryWorld()
{
	theme = new ThemeLoader("Themes/Erio/Library.xml");
	
	lastScreenWidth = 0;
	lastScreenHeight = 0;
}

void openFileThread_(void)
{
	std::string file = OpenFileDialog();
	updateWindowTitle(getAbsoluteFileName(file));
	
	FMOD::Sound *sound;
	FMOD::Channel *channel = 0;
	FMOD_RESULT result;
	
	result = g_FSystem -> createSound(file.c_str(), FMOD_SOFTWARE, 0, &sound);
	
	if (!fModError(result))
	{
		result = g_FSystem -> playSound(FMOD_CHANNEL_FREE, sound, 0, &channel);
		fModError(result);
	}
}

sf::Thread openFileThread(&openFileThread_);

void LibraryWorld::input(sf::Event &event)
{
	switch (event.type)
	{
		case sf::Event::Resized:
			SCREEN_WIDTH = event.size.width;
			SCREEN_HEIGHT = event.size.height;
			if (lastScreenWidth != SCREEN_WIDTH || lastScreenHeight != SCREEN_HEIGHT)
			{
				lastScreenWidth = SCREEN_WIDTH;
				lastScreenHeight = SCREEN_HEIGHT;
				theme -> repaint();
			}
		break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				openFileThread.launch();
			}
		break;
	}
}

void LibraryWorld::draw(sf::RenderWindow &App)
{
	theme -> draw(App);
}

void LibraryWorld::update(int deltaTime)
{
	
}