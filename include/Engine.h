#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Cake.h"


class Engine :public sf::RenderWindow
{
    private:
        Player player1;
        int acceleration;

    public:
        Engine();
        ~Engine();
        int runGame(sf::RenderWindow &window);
        bool collider(sf::Sprite &main, sf::Sprite &other, float push, sf::Vector2f mainPos);
};

#endif // ENGINE_H
