#include "player.hpp"
#include "raymath.h"

Player::Player(float windowWidth, float windowHeight)
{
    width = windowWidth / 2;
    height = windowHeight / 2;
}

Vector2 Player::getScreenPos() const
{
    return Vector2{width, height};
}

void Player::applyMovement(Vector2 direction)
{
    if (Vector2Length(direction) != 0)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
    }
}

void Player::tick(float deltaTime)
{
    if (IsKeyDown(KEY_A))
        velocity.x--;
    if (IsKeyDown(KEY_D))
        velocity.x++;
    if (IsKeyDown(KEY_W))
        velocity.y--;
    if (IsKeyDown(KEY_S))
        velocity.y++;

    applyMovement(velocity);
    velocity = {};

    DrawRectangle(getScreenPos().x, getScreenPos().y, 50, 120, RED);
}
