#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

class Player
{

public:
    //Constructor of the class
    Player(float windowWidth, float windowHeight);

    // Function responsible for Draw the Player and set worldPos
    void tick(float deltaTime);
private:
    // Function that gets the world Position of the player
    Vector2 getWorldPos(){return worldPos;};

    // Set the location of the player on the screen
    Vector2 getScreenPos();

    Vector2 worldPos{};
    Vector2 velocity{};

    float width, height;
    float speed{4.f};
};

#endif