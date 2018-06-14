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
    imgWidth = (tileMapTexture.getSize().x/13);
    tileMap.setTextureRect(sf::IntRect (0, 0, imgWidth, imgHeight));
    tileMap.setScale(1.5, 1.5);
    tileMap.setPosition(0, 0);
}

Level::~Level()
{
    //dtor
}

void Level::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(tileMap, states);
}

void Level::setNewPossiotion(int i, int j)
{
    tileMap.setPosition(((i*imgHeight*1.5)-3*imgWidth), (j*imgWidth*1.5));
}

void Level::changeTexture(int counter)
{
    switch(counter)
    {
    case 1:
        tileMap.setTextureRect (sf::IntRect(0, 0, imgWidth, imgHeight));
        break;
    case 2:
        tileMap.setTextureRect (sf::IntRect(imgWidth, 0, imgWidth, imgHeight));
        break;
    case 3:
        tileMap.setTextureRect (sf::IntRect(imgWidth+imgWidth, 0, imgWidth, imgHeight));
        break;
    default:
        break;
    }
}
