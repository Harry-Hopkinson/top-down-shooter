#pragma once

#include "raylib.h"

class TexturesClass
{
public:
	void LoadTextures();
	void UnloadTextures();

	Texture2D PlayerIdleTexture;
	Texture2D PlayerRunTexture;
	Texture2D SettingsTexture;
};
