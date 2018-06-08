#include "Level.h"

Level::Level()
{
    if(!tileMapTexture.loadFromFile("textures/Tileset.png"))
    {
        MessageBox(0,"Textures not found!","ERROR",0);
        return;
    }
    wskTileMapTexture = &tileMapTexture;
    tileMap.setTexture(*wskTileMapTexture);
    imgHeight = (tileMapTexture.getSize().y/8);
    imgWidth = (tileMapTexture.getSize().x/14);
    tileMap.setTextureRect(sf::IntRect (0, 0, imgWidth, imgHeight));
    tileMap.setScale(1.5, 1.5);
    tileMap.setPosition(0, 600);
}

Level::~Level()
{
    //dtor
}

void Level::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(tileMap, states);
}
