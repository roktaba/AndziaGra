#include "AmmoHeart.h"

AmmoHeart::AmmoHeart()
{
    if(!heartTexture.loadFromFile("textures/hearts.png"))
    {
        MessageBox(0,"Textures not found!","ERROR",0);
        return;
    }
    wskHeartTexture = &heartTexture;
    ammoSprite.setTexture(*wskHeartTexture);
    ammoSprite.setPosition(100, 500);
    imgHeight = (heartTexture.getSize().y);
    imgWidth =
     (heartTexture.getSize().x/6);
    ammoSprite.setTextureRect(sf::IntRect (0, 0, imgWidth, imgHeight));
}

AmmoHeart::~AmmoHeart()
{
//std::cout<<"test"<<std::endl;
}

void AmmoHeart::uptade(float dt)
{
    if (timer.getElapsedTime().asSeconds() >= 0.2)
    {
        ammoSprite.setTextureRect(sf::IntRect((imgWidth*imgCounter), 0, imgWidth, imgHeight));
        timer.restart();
        imgCounter++;
        if (imgCounter > 8)
            imgCounter = 0;
    }
}
