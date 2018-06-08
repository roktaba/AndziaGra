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
        int tabLvl [6][10];
        bool mapLoaded;

    public:
        Engine();
        ~Engine();
        int runGame(sf::RenderWindow &window);
        void loadMap();
};

#endif // ENGINE_H
