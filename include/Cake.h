#ifndef CAKE_H
#define CAKE_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>


class Cake :public sf::Drawable,
    sf::Transformable
{
private:
    int hp;
    int speed;
    bool canHurt;
    bool isAlive;
    sf::Texture mobTexture;
    sf::Texture *wskmobTexture;
    sf::Vector2f velocity;
    float imgWidth, imgHeight;

    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;

    public:
        sf::Sprite mobSprite;
        Cake();
        ~Cake();
    void uptade(float dt, int acceleration);
};

#endif // CAKE_H
