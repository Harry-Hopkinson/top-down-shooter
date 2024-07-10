#include "Textures.hpp"

void TexturesClass::LoadTextures()
{
    PlayerIdleTexture = LoadTexture("../assets/IDLE.png"); 
    PlayerRunTexture = LoadTexture("../assets/Run.png");
    SettingsTexture = LoadTexture("../assets/COG.png");
}

void TexturesClass::UnloadTextures()
{
    UnloadTexture(PlayerIdleTexture);
    UnloadTexture(PlayerRunTexture);
    UnloadTexture(SettingsTexture);
}
