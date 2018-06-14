#include "Engine.h"

Engine::Engine()
{
    acceleration = 0;
    mapLoaded = false;
    mapCounter = 0;
}

Engine::~Engine()
{
    std::cout<<"Engine destroyed"<<std::endl;
}

int Engine::runGame(sf::RenderWindow &window)
{
    Player player1;
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1280, 960));
    std::vector <Level> platform;
    Level lvl;
    Background lvl1Background(window.getSize().x, window.getSize().y);
    if (mapLoaded==false)
    {
    std::ifstream plik;
    std::string nazwa = "lvl1.txt";
    plik.open (nazwa.c_str(), std::ios::in);
    if (plik.good()==false)
    {
        MessageBox(0,"lvl1.txt not found!","ERROR",0);
    }
    int x=0;
    while (!plik.eof())
    {
        for (int j=0; j<10; j++)
        {
            std::string line;
            std::getline(plik, line);
            for (int i=0; i<line.size(); i++)
            {
                tabLvl[j][i] = (line[i] - '0');
                if (tabLvl[j][i] != 0)
                {
                    platform.push_back(lvl);
                    platform[platform.size()-1].setNewPossiotion(i, j);
                    platform[platform.size()-1].changeTexture(tabLvl[j][i]);
                }

            }
        }
    }
    plik.close();
       // loadMap(platform, lvl);
        mapLoaded=true;
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
       // player1.collision(0.0, ciastko[0].mobSprite);
        for (int i=0; i<platform.size(); i++)
        {
            player1.collision(0.0, platform[i].tileMap);
        }
        //ciastko[0].uptade(dt, acceleration);
        view.setCenter((player1.getPlayerPos().x +300), (window.getSize().y/2));
        window.clear();
        window.setView(view);
        lvl1Background.setPos(player1.getPlayerPos().x);
        window.draw(lvl1Background);
        for (int i=0; i<platform.size(); i++)
        {
            window.draw(platform[i]);
        }
        window.draw(player1);
        window.draw(ciastko[0]);
        window.display();
    }
}
