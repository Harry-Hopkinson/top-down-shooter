#pragma once

#include "raylib.h"
#include <string>

class PlayerClass
{
public:
    std::string Name;
    Vector2 Position;
    float Speed;
    Texture2D PlayerTexture;
    PlayerClass();
    void Update();
    void Draw();
    void SetTexture(Texture2D texture);
};
