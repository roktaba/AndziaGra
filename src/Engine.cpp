#include "Engine.h"

Engine::Engine()
{
    acceleration = 0;
}

Engine::~Engine()
{
    std::cout<<"Engine destroyed"<<std::endl;
}

int Engine::runGame(sf::RenderWindow &window)
{
    Player player1;
    std::vector <Cake> ciastko;
    Cake cake1;
    for (int i=0; i<1; i++)
    {
        ciastko.push_back(cake1);
    }
    sf::Clock deltaTime;
    while (true)
    {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            return 0;
        sf::Event akcjaOkna;
        while (window.pollEvent(akcjaOkna))
        {
            switch (akcjaOkna.type)
            case sf::Event::Closed:
            return 0;
            break;
        }
        float dt = deltaTime.restart().asSeconds();
        player1.uptade(dt);
        player1.collision(0.0, ciastko[0].mobSprite);
        //ciastko[0].uptade(dt, acceleration);
        window.clear();
        window.draw(player1);
        window.draw(ciastko[0]);
        window.display();
    }
}
