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
        float imgWidth, imgHeight;
        int imgCounter;
        bool canJump;
        float jumpHeight;
        sf::Sprite playerSprite;
        bool life;

        virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;

    public:
        Player();
        ~Player();
        void uptade(float dt);
        void setJump();
        bool collision(float push, sf::Sprite &other);
        sf::Vector2f getPlayerPos();
        void changeLifeStatus();
        bool checkLife(double y);
};

#endif // PLAYER_H
