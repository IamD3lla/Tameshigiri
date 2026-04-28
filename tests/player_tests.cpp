#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

#include <player/include/player.hpp>

namespace
{
constexpr float kTolerance{0.001f};

bool nearlyEqual(float left, float right)
{
    return std::fabs(left - right) <= kTolerance;
}

void expectVector(const std::string& testName, Vector2 actual, Vector2 expected)
{
    if (!nearlyEqual(actual.x, expected.x) || !nearlyEqual(actual.y, expected.y))
    {
        std::cerr << testName << " failed: expected (" << expected.x << ", " << expected.y
                  << "), got (" << actual.x << ", " << actual.y << ")\n";
        std::exit(EXIT_FAILURE);
    }
}

void testConstructorCentersPlayerOnScreen()
{
    Player player{800.f, 600.f};

    expectVector("testConstructorCentersPlayerOnScreen", player.getScreenPos(), {400.f, 300.f});
}

void testConstructorStartsAtWorldOrigin()
{
    Player player{800.f, 600.f};

    expectVector("testConstructorStartsAtWorldOrigin", player.getWorldPos(), {0.f, 0.f});
}

void testHorizontalMovementUsesPlayerSpeed()
{
    Player player{800.f, 600.f};

    player.applyMovement({1.f, 0.f});

    expectVector("testHorizontalMovementUsesPlayerSpeed", player.getWorldPos(), {4.f, 0.f});
}

void testZeroMovementDoesNotChangePosition()
{
    Player player{800.f, 600.f};

    player.applyMovement({0.f, 0.f});

    expectVector("testZeroMovementDoesNotChangePosition", player.getWorldPos(), {0.f, 0.f});
}

void testDiagonalMovementIsNormalized()
{
    Player player{800.f, 600.f};
    const float normalizedStep = 4.f / std::sqrt(2.f);

    player.applyMovement({1.f, 1.f});

    expectVector("testDiagonalMovementIsNormalized", player.getWorldPos(), {normalizedStep, normalizedStep});
}
}

int main(int argc, char** argv)
{
    const std::unordered_map<std::string, void (*)()> tests{
        {"constructor_centers_player_on_screen", testConstructorCentersPlayerOnScreen},
        {"constructor_starts_at_world_origin", testConstructorStartsAtWorldOrigin},
        {"horizontal_movement_uses_player_speed", testHorizontalMovementUsesPlayerSpeed},
        {"zero_movement_does_not_change_position", testZeroMovementDoesNotChangePosition},
        {"diagonal_movement_is_normalized", testDiagonalMovementIsNormalized},
    };

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <test_name>\n";
        return EXIT_FAILURE;
    }

    const auto test = tests.find(argv[1]);
    if (test == tests.end())
    {
        std::cerr << "Unknown test: " << argv[1] << "\n";
        return EXIT_FAILURE;
    }

    test->second();

    return EXIT_SUCCESS;
}
