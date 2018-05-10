#include "Engine.h"

Engine::Engine()
{
    acceleration = 981;
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
        player1.uptade(dt, acceleration);
        ciastko[0].uptade(dt, acceleration);
        if (collider(player1.playerSprite, ciastko[0].mobSprite, 0.5, player1.prevPos))
        {
            player1.setJump();
        }
        window.clear();
        window.draw(player1);
        window.draw(ciastko[0]);
        window.display();
    }
}

bool Engine::collider(sf::Sprite &main, sf::Sprite &other, float push, sf::Vector2f mainPos)
{
    sf::Vector2f mainPosition (main.getPosition());
    sf::Vector2f otherPosition (other.getPosition());

    sf::Vector2f mainHalfSize ((main.getGlobalBounds().width/2), (main.getGlobalBounds().height/2));
    sf::Vector2f otherHalfSize ((other.getGlobalBounds().width/2), (other.getGlobalBounds().height/2));

    float deltaX = otherPosition.x - mainPosition.x;
    float deltaY = otherPosition.y - mainPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + mainHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + mainHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f)
    {
        push = std::min(std::max(push, 0.0f), 1.0f);

        if (intersectX > intersectY)
        {
            if (deltaX > 0.0f)
            {
                main.move(intersectX * (1.0 - push), 0.0f);
                other.move(-intersectX * push, 0.0f);
            }
            else
            {
                main.move(-intersectX * (1.0 - push), 0.0f);
                other.move(intersectX * push, 0.0f);
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                main.setPosition(main.getPosition().x, mainPos.y);
                return true;
            }
        }
    }
    return false;
}
