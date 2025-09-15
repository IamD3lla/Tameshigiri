#include "player.hpp"

Player::Player(float windowWidth, float windowHeight)
{
    width = windowWidth / 2;
    height = windowHeight / 2;
}

Vector2 Player::getScreenPos()
{
    return Vector2{width, height};
}

void Player::tick(float deltaTime)
{
    DrawRectangle(getScreenPos().x, getScreenPos().y, 50, 100, BLUE);
}