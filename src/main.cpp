#include "raylib.h"

#include <string>

class Game
{
private:
    const int ScreenWidth = 1600;
    const int ScreenHeight = 960;
    const int MaxInputChars = 9;

    int LetterCount = 0;
    int FramesCounter = 0;

    Rectangle TextBox = { static_cast<float>(ScreenWidth / 2.0f - 100), static_cast<float>(ScreenHeight / 2.0f), 225, 50 };

    struct Player
    {
        std::string Name;
        Vector2 Position;
        float Speed;
    };

    enum GameScreen
    {
        TitleScreen = 0,
        EnterNameScreen = 1,
        GamePlayScreen = 2,
        SettingsScreen = 3
    };

    Player player;

    enum GameScreen CurrentScreen = GameScreen::TitleScreen;

    Texture2D PlayerTexture;
    Texture2D SettingsTexture;

    bool MouseOnText;

public:
    Game()
    {
        InitWindow(ScreenWidth, ScreenHeight, "2D Platformer");
        SetTargetFPS(120);

        PlayerTexture = LoadTexture("../assets/IDLE.png");
        SettingsTexture = LoadTexture("../asets/COG.png");
        MouseOnText = false;
    }

    ~Game()
    {
        UnloadTexture(PlayerTexture);
        UnloadTexture(SettingsTexture);
        CloseWindow();
    }

    void Drawing()
    {
        BeginDrawing();
        ClearBackground(WHITE);

        switch (CurrentScreen)
        {
            case TitleScreen:
            {
                int PlatformerText = MeasureText("2D Platformer", 40);
                int EnterToStartText = MeasureText("Press Enter to Start", 35);
                DrawText("2D Platformer", (GetScreenWidth() / 2) - (PlatformerText / 2 - 20), GetScreenHeight() / 2 - 75, 40, BLACK);
                DrawText("Press Enter to Start", (GetScreenWidth() / 2) - (EnterToStartText / 2), GetScreenHeight() / 2, 40, BLACK);
                DrawRectangle(760, 600, 100, 100, RED);
                break;
            }
            case EnterNameScreen:
            {
                DrawText("INPUT YOUR NAME!", ScreenWidth / 2 - 90, ScreenHeight / 2 + 75, 20, GRAY);
                DrawText("Press Enter to Continue", ScreenWidth / 2 - 110, ScreenHeight / 2 + 100, 20, GRAY);

                DrawRectangleRec(TextBox, LIGHTGRAY);

                if (MouseOnText)
                    DrawRectangleLines((int)TextBox.x, (int)TextBox.y, (int)TextBox.width, (int)TextBox.height, RED);
                else
                    DrawRectangleLines((int)TextBox.x, (int)TextBox.y, (int)TextBox.width, (int)TextBox.height, DARKGRAY);

                DrawText(player.Name.c_str(), (int)TextBox.x + 5, (int)TextBox.y + 8, 40, MAROON);
                DrawText(TextFormat("INPUT CHARS: %i/%i", LetterCount, MaxInputChars), 315, 250, 20, DARKGRAY);

                if (MouseOnText)
                {
                    if (LetterCount < MaxInputChars)
                    {
                        if (((FramesCounter / 20) % 2) == 0) DrawText("_", (int)TextBox.x + 8 + MeasureText(player.Name.c_str(), 40), (int)TextBox.y + 12, 40, MAROON);
                    }
                }
                break;
            }
            case GamePlayScreen:
            {
                DrawTexture(PlayerTexture, 15, 40, WHITE);
                DrawText("Game Screen", 20, 20, 40, DARKGRAY);
                break;
            }
            case SettingsScreen:
            {
                DrawText("Settings Screen", 20, 20, 40, DARKGRAY);
                break;
            }
            default:
                break;
        }

        EndDrawing();
    }

    void Run()
    {
        while (!WindowShouldClose())
        {
            switch (CurrentScreen)
            {
                case TitleScreen:
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        CurrentScreen = EnterNameScreen;
                    }
                    break;
                case EnterNameScreen:
                    if (CheckCollisionPointRec(GetMousePosition(), TextBox)) MouseOnText = true;
                    else MouseOnText = false;

                    if (MouseOnText)
                    {
                        SetMouseCursor(MOUSE_CURSOR_IBEAM);
                        int key = GetCharPressed();

                        while (key > 0)
                        {
                            if ((key >= 32) && (key <= 125) && (LetterCount < MaxInputChars))
                            {
                                player.Name += (char)key;
                                LetterCount++;
                            }

                            key = GetCharPressed();
                        }

                        if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && LetterCount > 0)
                        {
                            LetterCount--;
                            player.Name.pop_back();
                        }
                    }
                    else
                    {
                        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                    }

                    if (MouseOnText) FramesCounter++;
                    else FramesCounter = 0;

                    if (IsKeyPressed(KEY_ENTER) && LetterCount > 0)
                    {
                        CurrentScreen = GamePlayScreen;
                    }

                    break;
                case GamePlayScreen:
                    SetMouseCursor(MOUSE_CURSOR_CROSSHAIR);
                    break;
                case SettingsScreen:
                    break;
                default:
                    break;
            }

            Drawing();
        }
    }
};

int main()
{
    Game game;
    game.Run();
    return 0;
}
