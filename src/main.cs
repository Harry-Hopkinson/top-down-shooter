using Raylib_cs;
using System.Numerics;
using System.Text;

namespace RaylibGame;

struct Player
{
    public string Name;
    public string Description;
    public Vector2 Position;
    public float Speed;
}

enum GameScreen
{
    TitleScreen = 0,
    EnterNameScreen = 1,
    GamePlayScreen = 2,
    SettingScreen = 3,
}

class Program
{
    public const int ScreenWidth = 1600;
    public const int ScreenHeight = 960;
    public const Int16 MaxInputChars = 9;

    public static int FramesCounter = 0;
    public static int LetterCount = 0;
    public static GameScreen CurrentScreen = GameScreen.TitleScreen;
    public static Rectangle TextBox = new Rectangle(ScreenWidth / 2.0f - 100, ScreenHeight / 2.0f, 225, 50);

    static void Drawing(bool MouseOnText, StringBuilder Name)
    {
        Raylib.BeginDrawing();
        Raylib.ClearBackground(Color.White);

        switch (CurrentScreen)
        {
            case GameScreen.TitleScreen:
                int PlatformerText = Raylib.MeasureText("2D Platformer", 40);
                int EnterToStartText = Raylib.MeasureText("Press Enter to Start", 35);
                Raylib.DrawText("2D Platformer", (Raylib.GetScreenWidth() / 2) - (PlatformerText / 2 - 20), Raylib.GetScreenHeight() / 2 - 75, 40, Color.Black);
                Raylib.DrawText("Press Enter to Start", (Raylib.GetScreenWidth() / 2) - (EnterToStartText / 2), Raylib.GetScreenHeight() / 2, 40, Color.Black);
                Raylib.DrawRectangle(760, 600, 100, 100, Color.Red);
                break;
            case GameScreen.EnterNameScreen:
                Raylib.DrawText("INPUT YOUR NAME!", ScreenWidth / 2 - 90, ScreenHeight / 2 + 75, 20, Color.Gray);
                Raylib.DrawText("Press Enter to Continue", ScreenWidth / 2 - 110, ScreenHeight / 2 + 100, 20, Color.Gray);

                Raylib.DrawRectangleRec(TextBox, Color.LightGray);

                if (MouseOnText)
                {
                    Raylib.DrawRectangleLines((int)TextBox.X, (int)TextBox.Y, (int)TextBox.Width, (int)TextBox.Height, Color.Red);
                }
                else
                {
                    Raylib.DrawRectangleLines((int)TextBox.X, (int)TextBox.Y, (int)TextBox.Width, (int)TextBox.Height, Color.DarkGray);
                }

                Raylib.DrawText(Name.ToString(), (int)TextBox.X + 5, (int)TextBox.Y + 8, 40, Color.Maroon);
                Raylib.DrawText(string.Format("INPUT CHARS: {0}/{1}", LetterCount, MaxInputChars), ScreenWidth / 2 - 85, ScreenHeight / 2 - 50, 20, Color.DarkGray);

                if (MouseOnText)
                {
                    if (LetterCount < MaxInputChars)
                    {
                        if (((FramesCounter / 20) % 2) == 0) Raylib.DrawText("_", (int)TextBox.X + 8 + Raylib.MeasureText(Name.ToString(), 40), (int)TextBox.Y + 12, 40, Color.Maroon);
                    }
                }
                break;
            case GameScreen.GamePlayScreen:
                break;
            case GameScreen.SettingScreen:
                Raylib.DrawText("Settings Screen", Raylib.GetScreenWidth() / 2, Raylib.GetScreenHeight() / 2, 20, Color.Black);
                break;
            default:
                break;
        }

        Raylib.EndDrawing();
    }

    public static void Main()
    {
        Raylib.InitWindow(ScreenWidth, ScreenHeight, "2D Platformer");
        Raylib.SetTargetFPS(120);

        StringBuilder Name = new StringBuilder(MaxInputChars + 1);

        bool MouseOnText = false;

        while (!Raylib.WindowShouldClose())
        {
            // Input Logic
            switch (CurrentScreen)
            {
                case GameScreen.TitleScreen:
                    if (Raylib.IsKeyPressed(KeyboardKey.Space))
                    {
                        CurrentScreen = GameScreen.EnterNameScreen;
                    }
                    break;
                case GameScreen.EnterNameScreen:
                    if (Raylib.CheckCollisionPointRec(Raylib.GetMousePosition(), TextBox)) MouseOnText = true;
                    else MouseOnText = false;

                    if (MouseOnText)
                    {
                        Raylib.SetMouseCursor(MouseCursor.IBeam);
                        int key = Raylib.GetCharPressed();

                        while (key > 0)
                        {
                            if ((key >= 32) && (key <= 125) && (LetterCount < MaxInputChars))
                            {
                                Name.Append((char)key);
                                LetterCount++;
                            }

                            key = Raylib.GetCharPressed();
                        }

                        if (Raylib.IsKeyPressed(KeyboardKey.Backspace))
                        {
                            LetterCount--;
                            if (LetterCount < 0) LetterCount = 0;
                            Name.Length = LetterCount;
                        }
                    }
                    else
                    {
                        Raylib.SetMouseCursor(MouseCursor.Default);
                    }

                    if (MouseOnText) FramesCounter++;
                    else FramesCounter = 0;

                    if (Raylib.IsKeyPressed(KeyboardKey.Enter) && LetterCount > 0)
                    {
                        CurrentScreen = GameScreen.GamePlayScreen;
                    }

                    break;
                case GameScreen.GamePlayScreen:
                    Raylib.SetMouseCursor(MouseCursor.Crosshair);
                    break;
                case GameScreen.SettingScreen:
                    break;
                default:
                    break;
            }
            Drawing(MouseOnText, Name);
        }

        Raylib.CloseWindow();
    }
}

