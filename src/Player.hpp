#pragma once

#include "raylib.h"
#include <string>

#include "Animations.hpp"

class PlayerClass : AnimationsClass
{
public:
    std::string Name;
    Vector2 Position;
    Vector2 ScaledPosition = { 0.0f, 0.0f };
    float Speed;
    Texture2D PlayerTexture;
    Rectangle FrameRec;

    PlayerClass();
    void Update();
    void Draw();
    void SetTexture(const Texture2D* texture);

    enum PlayerState
    {
	IDLE,
	RUN
    };
private:
    PlayerState State;
};
