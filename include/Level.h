#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>


class Level  :public sf::Drawable, sf::Transformable
{
    private:
        virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;

        sf::Texture tileMapTexture;
        sf::Texture *wskTileMapTexture;
        float imgWidth, imgHeight;


    public:
        sf::Sprite tileMap;
        Level();
        ~Level();
};

#endif // LEVEL_H
