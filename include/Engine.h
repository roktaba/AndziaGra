#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Cake.h"
#include "Level.h"


class Engine :public sf::RenderWindow
{
    private:
        Player player1;
        int acceleration;
        int tabLvl [10][10];
        bool mapLoaded;
        int mapCounter;

    public:
        Engine();
        ~Engine();
        int runGame(sf::RenderWindow &window);

};

#endif // ENGINE_H
