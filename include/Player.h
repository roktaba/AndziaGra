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
        sf::Vector2f prevPos;
        float mvspeed;
        float imgWidth, imgHeight;
        int imgCounter;
        bool canJump;
        float jumpHeight;


        virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;

    public:
        Player();
        ~Player();
        sf::Sprite playerSprite;
        void uptade(float dt);
        void setJump();
        bool collision(float push, sf::Sprite &other);
};

#endif // PLAYER_H
