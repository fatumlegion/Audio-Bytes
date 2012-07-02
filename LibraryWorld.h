#ifndef LIBRARYWORLD_H
#define LIBRARYWORLD_H
#include "WorldBase.h"
#include "ThemeLoader.h"
class LibraryWorld : public WorldBase
{
	private:
		ThemeLoader *theme;
		int lastScreenWidth;
		int lastScreenHeight;
	public:
		LibraryWorld();
		void input(sf::Event &event);
		void draw(sf::RenderWindow &App);
		void update(int deltaTime);
};
#endif