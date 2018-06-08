#include "Engine.h"

Engine::Engine()
{
    acceleration = 0;
    mapLoaded = false;
}

Engine::~Engine()
{
    std::cout<<"Engine destroyed"<<std::endl;
}

int Engine::runGame(sf::RenderWindow &window)
{
    Player player1;

    std::vector <Level> platform;
    Level lvl;
    if (mapLoaded==false)
    {
        loadMap();
        mapLoaded=true;
    }
    for (int i=0; i<1; i++)
    {
        platform.push_back(lvl);
    }
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
        player1.collision(0.0, platform[0].tileMap);
        //ciastko[0].uptade(dt, acceleration);
        window.clear();
        window.draw(player1);
        window.draw(ciastko[0]);
        window.draw(platform[0]);
        window.display();
    }
}


void Engine::loadMap()
{
    std::ifstream plik;
    std::string nazwa = "lvl1.txt";
    plik.open (nazwa.c_str(), std::ios::in);
    if (plik.good()==false)
    {
        MessageBox(0,"lvl1.txt not found!","ERROR",0);
        return;
    }
    int x=0;
    while (plik.eof())
    {
        for (int j=0; j<6; j++)
        {
            std::string line;
            std::getline(plik, line);
            for (int i=0; i<line.size();i++)
            {
                tabLvl[j][i] = line[i];
            }
        }
    }
    plik.close();
}
