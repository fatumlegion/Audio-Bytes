#include "ThemeLoader.h"
#include "helper.h"
#include <stdio.h>
#include "main.h"

ThemeLoader::ThemeLoader(std::string index)
{
	vw_main.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	Load(index);
}

void ThemeLoader::Load(std::string index)
{
	try
	{
		ticpp::Document doc(index.c_str());
		doc.LoadFile();

		ticpp::Iterator<ticpp::Element> theme;
		for (theme = theme.begin(doc.FirstChildElement()); theme != theme.end(); theme++)
		{
			std::string CurrentBlock = theme -> Value();
			
			if (CurrentBlock == "AssetLoader")
			{
				ticpp::Iterator<ticpp::Element> asset;
				for (asset = asset.begin(theme.Get()); asset != asset.end(); asset++)
				{
					std::string id = asset -> GetAttribute("id");
					std::string type = asset -> GetAttribute("type");
					std::string location = asset -> GetAttribute("location");
					
					if (type == "image")
					{
						cont_txtr[id].ID = id;
						cont_txtr[id].Texture.loadFromFile(location);
					}
				}
			}
			
			if (CurrentBlock == "ObjectStack")
			{
				ticpp::Iterator<ticpp::Element> object;
				for (object = object.begin(theme.Get()); object != object.end(); object++)
				{
					std::string id = object -> GetAttribute("id");
					std::string type = object -> GetAttribute("type");
					std::string asset = object -> GetAttribute("asset");
					
					if (type == "sprite")
					{
						int x = atoi(object -> GetAttribute("x").c_str());
						int y = atoi(object -> GetAttribute("y").c_str());
						bool repeat_x = StrToBool(object -> GetAttribute("repeat-x"));
						bool repeat_y = StrToBool(object -> GetAttribute("repeat-y"));
						
						nkSprite sprite;
						sprite.ID = id;
						sprite.repeat_x = repeat_x;
						sprite.repeat_y = repeat_y;
						sprite.Sprite.setTexture(cont_txtr[asset].Texture);
						sprite.Sprite.setPosition(x, y);
						cont_sprites.push_back(sprite);
					}
				}
			}
			
			if (CurrentBlock == "EventStack")
			{
				printf("Let's link these events.\n");
			}
		}
	}
	catch (ticpp::Exception &ex)
	{
		printf("%s\n", ex.what());
	}
}

void ThemeLoader::input(sf::Event &event)
{
}

void ThemeLoader::repaint(void)
{
	vw_main.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	cont_sprites_drawable.clear();
	
	for (int i = 0; i < cont_sprites.size(); i++)
	{		
		if (cont_sprites[i].repeat_x == true && cont_sprites[i].repeat_y == false)
		{
			for (int cx = cont_sprites[i].Sprite.getPosition().x; cx < SCREEN_WIDTH; cx += cont_sprites[i].Sprite.getTextureRect().width)
			{
				sf::Sprite sprite;
				sprite.setPosition(cx, cont_sprites[i].Sprite.getPosition().y);
				sprite.setTexture(*cont_sprites[i].Sprite.getTexture());
				cont_sprites_drawable.push_back(sprite);
			}
		}
		
		if (cont_sprites[i].repeat_x == false && cont_sprites[i].repeat_y == true)
		{
			for (int cy = cont_sprites[i].Sprite.getPosition().y; cy < SCREEN_HEIGHT; cy += cont_sprites[i].Sprite.getTextureRect().height)
			{
				sf::Sprite sprite;
				sprite.setPosition(cont_sprites[i].Sprite.getPosition().x, cy);
				sprite.setTexture(*cont_sprites[i].Sprite.getTexture());
				cont_sprites_drawable.push_back(sprite);
			}
		}
		
		if (cont_sprites[i].repeat_x == true && cont_sprites[i].repeat_y == true)
		{
			for (int cx = cont_sprites[i].Sprite.getPosition().x; cx < SCREEN_WIDTH; cx += cont_sprites[i].Sprite.getTextureRect().width)
			{
				for (int cy = cont_sprites[i].Sprite.getPosition().y; cy < SCREEN_HEIGHT; cy += cont_sprites[i].Sprite.getTextureRect().height)
				{
					sf::Sprite sprite;
					sprite.setPosition(cx, cy);
					sprite.setTexture(*cont_sprites[i].Sprite.getTexture());
					cont_sprites_drawable.push_back(sprite);
				}
			}
		}
	}
}

void ThemeLoader::draw(sf::RenderWindow &App)
{
	App.setView(vw_main);
	for (int i = 0; i < cont_sprites_drawable.size(); i++)
	{
		App.draw(cont_sprites_drawable[i]);
	}
}