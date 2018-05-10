#include "Player.h"

Player::Player()
{
    if(!playerTexture.loadFromFile("textures/andziaplayer.png"))
    {
        MessageBox(0,"Textures not found!","ERROR",0);
        return;
    }
    wskplayerTexture = &playerTexture;
    playerSprite.setTexture(*wskplayerTexture);
    imgHeight = (playerTexture.getSize().y/5);
    imgWidth = (playerTexture.getSize().x/10);
    playerSprite.setTextureRect(sf::IntRect (imgWidth, 0, imgWidth, imgHeight));
    playerSprite.setPosition(100, 300);
    velocity.x = 0;
    velocity.y = 0;
    mvspeed = 350;
    playerSprite.scale(0.5, 0.5);
    imgCounter = 0;
    canJump = true;
    jumpHeight = 200;
    ground = 500;
    timer.restart();
    prevPos = playerSprite.getPosition();
}

Player::~Player()
{
    std::cout<<"Player destroyed"<<std::endl;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(playerSprite, states);
}

void Player::uptade(float dt, int acceleration)
{
    velocity.x *= 0.0;
    prevPos = playerSprite.getPosition();

    ///////////////////////RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity.x = mvspeed;
        if (timer.getElapsedTime().asSeconds() >= 0.09)
        {
            playerSprite.setTextureRect(sf::IntRect((((imgCounter+7)*imgWidth)-25), 0, -imgWidth+70, imgHeight));
            timer.restart();
            imgCounter++;
            if (imgCounter > 2)
                imgCounter = 0;
        }
    }

    ///////////////////////LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x = -mvspeed;
        if (timer.getElapsedTime().asSeconds() >= 0.09)
        {
            playerSprite.setTextureRect(sf::IntRect((((imgCounter+6)*imgWidth)+55), 0, imgWidth-80, imgHeight));
            timer.restart();
            imgCounter++;
            if (imgCounter > 2)
                imgCounter = 0;
        }
    }

    ///////////////////////STAY
    if (!((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))))
    {
        if (timer.getElapsedTime().asSeconds() >= 0.2)
        {
            playerSprite.setTextureRect(sf::IntRect(((8*imgWidth)+62), (imgCounter * imgHeight), imgWidth-95, imgHeight));
            timer.restart();
            imgCounter++;
            if (imgCounter > 2)
                imgCounter = 1;
        }
    }

    /////////////////////JUMP
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&canJump)
    {
        canJump=false;
        velocity.y = -sqrtf(2.0 * acceleration * jumpHeight);
    }

    //////////////////////GRAVITY
    playerSprite.move(velocity * dt);
    if (playerSprite.getPosition().y > ground)
    {
        canJump = true;
        velocity.y = 0;
    } else velocity.y += acceleration * dt;
}

void Player::setJump()
{
    canJump = true;
}