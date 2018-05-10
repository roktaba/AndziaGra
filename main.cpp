#include <SFML/Graphics.hpp>
#include "GameMenu.h"
#include "Engine.h"

int main()
{
unsigned int screenwidht = 1280;
unsigned int screenheight = 960;
enum gameState {MENU,GAME,GAME_CLOSE};
gameState state = MENU;
sf::RenderWindow window(sf::VideoMode(screenwidht, screenheight), "Andzia Je Ciastko!", sf::Style::Titlebar | sf::Style::Close);

while (window.isOpen())
{
    sf::Event akcjaOkna;
    while (window.pollEvent(akcjaOkna))
    {
        switch (akcjaOkna.type)
        case sf::Event::Closed:
        window.close();
        break;
    }
    switch (state)
        {
            case GAME_CLOSE:
            {
                window.close();
                break;
            }
            case MENU:
            {
                GameMenu mainMenu;
                if ((mainMenu.startMenu(window))==1)
                    state=GAME;
                else
                if ((mainMenu.startMenu(window))==0)
                    state=GAME_CLOSE;
                break;
            }
            case GAME:
            {
                Engine gameEngine;
                if ((gameEngine.runGame(window)) == 0);
                    state=GAME_CLOSE;
                break;
            }
        }
}
return 0;
}
