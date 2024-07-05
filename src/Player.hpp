#pragma once

#include "raylib.h"
#include "Character.hpp"

class Player : public Character
{
public:
    Player();
    ~Player();

    void Update();
    void Draw();

    void LoadTextures();

    Texture2D PlayerTexture;
};
