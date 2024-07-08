#include "Player.hpp"

PlayerClass::PlayerClass() : Position{0, 0}, Speed(5.0f) {}

void PlayerClass::Update()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        Position.x += Speed;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        Position.x -= Speed;
    }
}

void PlayerClass::Draw()
{
    DrawTexture(PlayerTexture, Position.x, Position.y, WHITE);
}

void PlayerClass::SetTexture(Texture2D texture)
{
    PlayerTexture = texture;
}
