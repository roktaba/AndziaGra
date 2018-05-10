#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <cmath>


class Player :public sf::Drawable,
    sf::Transformable
{
    private:
        sf::Texture playerTexture;
        sf::Texture *wskplayerTexture;
        sf::Vector2f velocity;
        sf::Clock timer;
        float mvspeed;
        float ground;
        float imgWidth, imgHeight;
        int imgCounter;
        bool canJump;
        float jumpHeight;

        virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;

    public:
        sf::Vector2f prevPos;
        sf::Sprite playerSprite;
        Player();
        ~Player();
        void uptade(float dt, int acceleration);
        void setJump();
};

#endif // PLAYER_H
