#ifndef THEMELOADER_H
#define THEMELOADER_H
#include <SFML/Graphics.hpp>
#include "ticpp.h"
#include <string>
#include <vector>
#include <map>

struct nkTexture
{
	std::string ID;
	sf::Texture Texture;
};

struct nkObject
{
	std::string Type;
	void *Object;
};

struct nkSprite
{
	std::string ID;
	bool repeat_x;
	bool repeat_y;
	sf::Sprite Sprite;
};

class ThemeLoader
{
	private:
		//std::vector<nkTexture> cont_txtr;
		std::map<std::string, nkTexture> cont_txtr;
		std::vector<nkSprite> cont_sprites;
		std::vector<sf::Sprite> cont_sprites_drawable;
		sf::View vw_main;
	public:
		ThemeLoader(std::string index);
		void repaint(void);
		void Load(std::string index);
		void input(sf::Event &event);
		void draw(sf::RenderWindow &App);
};
#endif