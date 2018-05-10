#include "Cake.h"

Cake::Cake()
{
    if(!mobTexture.loadFromFile("textures/cakemob2.png"))
    {
        MessageBox(0,"Textures not found!","ERROR",0);
        return;
    }
    wskmobTexture = &mobTexture;
    mobSprite.setTexture(*wskmobTexture);
    mobSprite.setPosition(400, 200);
    imgHeight = (mobTexture.getSize().y/4);
    imgWidth = (mobTexture.getSize().x/9);
    hp = 1;
    speed = 200;
    canHurt = true;
    isAlive = true;
    velocity.x = 0;
    velocity.y = 0;
    mobSprite.setTextureRect(sf::IntRect (0, 0, imgWidth, imgHeight));
}

Cake::~Cake()
{
    std::cout<<"Cake destroyed"<<std::endl;
}

void Cake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(mobSprite, states);
}

void Cake::uptade(float dt, int acceleration)
{
    int ground = 500;
    mobSprite.move(velocity * dt);
    if (mobSprite.getPosition().y > (ground))
    {
        velocity.y = 0;
    } else velocity.y += acceleration * dt;
}
