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
};

#endif // ENGINE_H
