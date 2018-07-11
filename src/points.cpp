#include "points.h"

points::points()
{
    pkt = 0;

}

points::~points()
{
    //dtor
}

void points::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(cakesPoints, states);
}

void points::increasePkt()
{
    pkt++;
}
