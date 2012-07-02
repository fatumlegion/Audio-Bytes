#include <SFML/Graphics.hpp>
#include "WorldBase.h"
#include "LibraryWorld.h"
#include "helper.h"
#include "main.h"

int SCREEN_WIDTH = 900;
int SCREEN_HEIGHT = 600;
int SCREEN_BPP = 32;

sf::RenderWindow App;

WorldBase *TargetWorld;

FMOD::System *g_FSystem;

void setup_fmod(void)
{
	FMOD_RESULT result;
	unsigned int version;
	
	result = FMOD::System_Create(&g_FSystem);
	fModError(result);
	
	result = g_FSystem -> getVersion(&version);
	fModError(result);
	
	if (version < FMOD_VERSION)
	{
		printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
	}
	
	result = g_FSystem -> setOutput(FMOD_OUTPUTTYPE_ALSA);
	fModError(result);
	
	result = g_FSystem -> init(32, FMOD_INIT_NORMAL, 0);
	fModError(result);
}

void updateWindowTitle(std::string str)
{
	App.setTitle(str + " - AudioBytes");
}

int main(int argc, char** argv)
{
	App.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "AudioBytes", sf::Style::Default);
	App.setFramerateLimit(60);
	
	TargetWorld = new LibraryWorld();
	
	setup_fmod();
	
	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			TargetWorld -> input(event);
			switch (event.type)
			{
				case sf::Event::Closed:
					App.close();
				break;
			}
		}
	
		App.clear(sf::Color(100, 100, 100));
		TargetWorld -> draw(App);
		TargetWorld -> update(3);
		App.display();
	}
	
	return 0;
}