#pragma once

#include "Player.hpp"
#include "Textures.hpp"

class Game
{
private:
    const int ScreenWidth = 1200;
    const int ScreenHeight = 800;
    const int MaxInputChars = 9;

    int LetterCount = 0;
    int FramesCounter = 0;

    Rectangle TextBox;
    Rectangle SettingsArea;

    PlayerClass Player;

    enum GameScreen
    {
        TitleScreen = 0,
        EnterNameScreen = 1,
        GamePlayScreen = 2,
        SettingsScreen = 3
    };

    enum GameScreen CurrentScreen = GameScreen::TitleScreen;

    bool MouseOnText = false;

    TexturesClass Textures;

    void Drawing();

public:
    Game();
    ~Game();
    void Run();
};
