// このファイルで使うクラスや関数の宣言を読み込む。
#include "DxLib.h"
// このファイルで使うクラスや関数の宣言を読み込む。
#include "Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモードで起動する設定。
    ChangeWindowMode(TRUE);
    // 画面の幅・高さ・色のビット数を、初期化前に設定する。
    SetGraphMode(480, 854, 32);
    // 画面切り替え時の垂直同期待ちを無効にし、下の時間計算で更新を管理する。
    SetWaitVSyncFlag(FALSE);
    // DxLibを初期化する。失敗したら-1を返して終了する。
    if (DxLib_Init() == -1) return -1;
    // 直接画面に出さず、裏画面へ描画してからまとめて表示する。
    SetDrawScreen(DX_SCREEN_BACK);

    // Gameクラスの実体を作る。以降はgameを通じて関数を呼ぶ。
    Game game;
    // ループの前に1回だけ、ゲームで使う画像を読み込む。
    game.Load();

    // 描画速度に依存せず、移動・重力を1秒に60回更新する
    const double step = 1000000.0 / 60.0;
    LONGLONG previousTime = GetNowHiPerformanceCount();
    // doubleは小数を扱う型。まだ更新に使っていない経過時間をためる。
    double accumulated = 0.0;
    // whileは条件が成り立つ間繰り返す。閉じる操作やEscでループを終える。
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        const LONGLONG now = GetNowHiPerformanceCount();
        double elapsed = static_cast<double>(now - previousTime);
        previousTime = now;
        // 停止・ウィンドウ移動後に大量の更新をまとめて行わない
        if (elapsed > 100000.0) elapsed = 100000.0;
        accumulated += elapsed;
        bool updated = false;
        // 1回分の時間がたまるごとにゲームを更新する。
        while (accumulated >= step)
        {
            game.Update();
            accumulated -= step;
            updated = true;
        }
        if (updated)
        {
            // 前に描いた内容を消して、今回の描画を始める。
            ClearDrawScreen();
            game.Draw();
            // 裏画面に描き終えた内容を画面へ表示する。
            ScreenFlip();
        }
        // 1ミリ秒待ち、処理を回し続けてCPUを使い切ることを抑える。
        WaitTimer(1);
    }
    // DxLibを終了し、使用した資源を片付ける。
    DxLib_End();
    // 呼び出し元に0を返す。mainでは正常終了、Cameraの現在の実装では固定の座標0。
    return 0;
}