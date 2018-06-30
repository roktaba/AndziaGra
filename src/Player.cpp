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
    jumpHeight = 210;
    timer.restart();
    life = true;
    playerSprite.setOrigin(-50, 0);
}

Player::~Player()
{
    std::cout<<"Player destroyed"<<std::endl;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(playerSprite, states);
}

void Player::uptade(float dt)
{
    velocity.x *= 0.0;
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
        velocity.y = -sqrtf(2.0 * 981 * jumpHeight);
    }

    //////////////////////GRAVITY
    velocity.y += 981 * dt;
    playerSprite.move(velocity * dt);
    canJump=false;
}

void Player::setJump()
{
    canJump = true;
}

bool Player::collision(float push, sf::Sprite &other)
{
    sf::Vector2f mainPosition (playerSprite.getPosition());
    sf::Vector2f otherPosition (other.getPosition());

    sf::Vector2f mainHalfSize ((playerSprite.getGlobalBounds().width/2), (playerSprite.getGlobalBounds().height/2));
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
                playerSprite.move(intersectX * (1.0 - push), 0.0f);
                other.move(-intersectX * push, 0.0f);

            }
            else
            {
                playerSprite.move(-intersectX * (1.0 - push), 0.0f);
                other.move(intersectX * push, 0.0f);
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                playerSprite.move(0.0f, intersectY* (1.0f - push));
                other.move(0.0f, -intersectY * push);
                velocity.y = 0.0;
                setJump();
            }
            else
            {
                playerSprite.move(0.0f, -intersectY * (1.0f - push));
                other.move(0.0f, intersectY * push);
                if (velocity.y < 0)
                    velocity.y  = 0.0;
            }
        }
        return true;
    }
    return false;
}

sf::Vector2f Player::getPlayerPos()
{
    return playerSprite.getPosition();
}

void Player::changeLifeStatus()
{
    life=false;
}
bool Player::checkLife(double y)
{
    if (getPlayerPos().y > (y+100))
        changeLifeStatus();
    if (life==false)
        return false;
    if (life==true)
        return true;
}
