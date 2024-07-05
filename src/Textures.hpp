#pragma once

#include "raylib.h"

class TexturesClass
{
public:
	void LoadTextures();
	void UnloadTextures();

	Texture2D PlayerTexture;
	Texture2D SettingsTexture;
};
