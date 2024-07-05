#include "Textures.hpp"

void TexturesClass::LoadTextures()
{
    PlayerTexture = LoadTexture("../assets/IDLE.png");
    SettingsTexture = LoadTexture("../assets/COG.png");
}

void TexturesClass::UnloadTextures()
{
    UnloadTexture(PlayerTexture);
    UnloadTexture(SettingsTexture);
}
