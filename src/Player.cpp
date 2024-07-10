#include "Player.hpp"

#define MAX_FRAME_SPEED 10 
#define MIN_FRAME_SPEED  1

PlayerClass::PlayerClass()
{
    Position = { 350.0f, 280.0f };
    Speed = 5.0f;
    FramesCounter = 0;
    FramesSpeed = 8;
    CurrentFrame = 0;
    FrameRec = { 0.0f, 0.0f, 0.0f, 0.0f };
    State = PlayerState::IDLE;
}

void PlayerClass::Update()
{
    FramesCounter++;
    
    if (FramesCounter >= (60 / FramesSpeed))
    {
        FramesCounter = 0;
        CurrentFrame++;

        if (CurrentFrame > 5) CurrentFrame = 0;
        FrameRec.x = (float)CurrentFrame * (float)PlayerTexture.width / 6;
    }

    if (FramesSpeed > MAX_FRAME_SPEED) FramesSpeed = MAX_FRAME_SPEED;
    else if (FramesSpeed < MIN_FRAME_SPEED) FramesSpeed = MIN_FRAME_SPEED;

    if (IsKeyDown(KEY_RIGHT))
    {
        Position.x += Speed;
        State = RUN; 
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        Position.x -= Speed;
        State = RUN;
    }
    else State = IDLE;

    switch (State)
    {
        case IDLE:
            FramesSpeed = 4;
            break;
        case RUN:
            FramesSpeed = 8;
            break;
    }

    ScaledPosition = 
    { Position.x - (NewWidth - FrameRec.width ) / 2,
      Position.y - (NewHeight - FrameRec.height) / 2 
    };
}

void PlayerClass::Draw()
{
    DrawTexturePro(
        PlayerTexture,
        FrameRec,
        { ScaledPosition.x, ScaledPosition.y, NewWidth, NewHeight },
        { 0, 0 },
        0.0f,
        WHITE
    );
}

void PlayerClass::SetTexture(const Texture2D* texture)
{
    PlayerTexture = *texture;
    FrameRec = { 0.0f, 0.0f, (float)PlayerTexture.width / 6, (float)PlayerTexture.height };

    NewWidth = FrameRec.width * Scale;
    NewHeight = FrameRec.height * Scale;

    ScaledPosition = 
    { Position.x - (NewWidth - FrameRec.width ) / 2,
      Position.y - (NewHeight - FrameRec.height) / 2 
    };
}
