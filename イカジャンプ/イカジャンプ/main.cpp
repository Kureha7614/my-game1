#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
    SetGraphMode(480, 854, 32);
    SetWaitVSyncFlag(FALSE);
    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    Game game;
    game.Load();

    // 描画速度に依存せず、移動・重力を1秒に60回更新する
    const double step = 1000000.0 / 60.0;
    LONGLONG previousTime = GetNowHiPerformanceCount();
    double accumulated = 0.0;
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        const LONGLONG now = GetNowHiPerformanceCount();
        double elapsed = static_cast<double>(now - previousTime);
        previousTime = now;
        // 停止・ウィンドウ移動後に大量の更新をまとめて行わない
        if (elapsed > 100000.0) elapsed = 100000.0;
        accumulated += elapsed;
        bool updated = false;
        while (accumulated >= step)
        {
            game.Update();
            accumulated -= step;
            updated = true;
        }
        if (updated)
        {
            ClearDrawScreen();
            game.Draw();
            ScreenFlip();
        }
        WaitTimer(1);
    }
    DxLib_End();
    return 0;
}