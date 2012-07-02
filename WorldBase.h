#ifndef WORLDBASE_H
#define WORLDBASE_H
#include <SFML/Graphics.hpp>
class WorldBase
{
	public:
		virtual void input(sf::Event &event) = 0;
		virtual void draw(sf::RenderWindow &App) = 0;
		virtual void update(int deltaTime) = 0;
};
#endif