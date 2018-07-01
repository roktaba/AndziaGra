#include "Ammunition.h"

Ammunition::Ammunition()
{
    ammoCounter = 10;
    ammoRange = 500;
    ammoSpeed = 300;
    ammoDmg = 1;
    ammoVelocity.x = ammoSpeed;
    ammoVelocity.y = 0;
    timer.restart();
    imgCounter = 0;
    imgWidth = 0;
    imgWidth = 0;
}

Ammunition::~Ammunition()
{
    //dtor
}

void Ammunition::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(ammoSprite, states);
}

void Ammunition::setNewPossition(sf::Vector2f newPos)
{
    ammoSprite.setPosition(newPos.x, newPos.y);
}
