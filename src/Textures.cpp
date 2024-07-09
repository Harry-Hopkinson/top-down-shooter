#include "Textures.hpp"

void TexturesClass::LoadTextures()
{
    PlayerTexture = LoadTexture("../assets/Run.png");
    SettingsTexture = LoadTexture("../assets/COG.png");
}

void TexturesClass::UnloadTextures()
{
    UnloadTexture(PlayerTexture);
    UnloadTexture(SettingsTexture);
}
