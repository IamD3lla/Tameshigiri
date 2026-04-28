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

    Vector2 getWorldPos() const { return worldPos; }
    Vector2 getScreenPos() const;
    void applyMovement(Vector2 direction);
private:
    Vector2 worldPos{};
    Vector2 velocity{};

    float width, height;
    float speed{4.f};
};

#endif
