#pragma once
class Character
{
private:
    enum class State { Idle, Run, Jump, Fall };
    State state = State::Idle;
    int playerX = 200;
    float playerY = 696.0f;
    float previousY = 696.0f;
    float velocityY = 0.0f;
    // 描画領域には余白があるため、見える靴底を足元とする
    static constexpr float FootOffset = 82.0f;
    int PushCount = 0;     // ためた時間（ミリ秒）
    int PushStartTime = 0;
    bool isCharging = false;
    bool onGround = true;
    int imageHandle = -1;
public:
    void Load();
    void Draw();
    void Update();
    void CheckLanding(float left, float right, float top);
};