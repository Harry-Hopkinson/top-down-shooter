#pragma once

#include "raylib.h"

class Character
{
public:
    enum StateEnum { IDLE, RUN, DEAD };

protected:
	Vector2 Position;
	Vector2 Direction;
	float MovementSpeed;


	int MaxHealth;
	int CurrentHealth;

	float Scale;
	float AnimationSpeed;
};
