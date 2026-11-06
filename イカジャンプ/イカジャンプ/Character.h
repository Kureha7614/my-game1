// このヘッダーを同じソース内で何度も読み込まないための指定。
#pragma once
// このファイルで使うクラスや関数の宣言を読み込む。
#include"Animation.h"
// 関連するデータと処理をまとめるクラス。
class Character
{
// このクラスの内部から使う変数や型。
private:
    enum class State { Idle, Run, Jump, Fall };
    // enum classは状態に名前を付ける仕組み。現在の状態は待機から始める。
    State state = State::Idle;
    // Animationクラスの実体（オブジェクト）を作り、キャラが持つ。
    Animation animation;
    // 前回のアニメーションの状態。今の状態と比較するために覚えておく。
    State animationState = State::Idle;
    // boolはtrueかfalseを持つ。trueなら左向き、falseなら右向き。
    bool facingLeft = false;
    // 今回の更新で横に移動したかを覚える。
    bool movingHorizontally = false;
    // intは整数。画面のX座標は右へ行くほど大きくなる。
    int playerX = 200;
    // floatは小数を扱う。Y座標は下へ行くほど大きくなる。fはfloatの数値を表す。
    float playerY = 696.0f;
    // 移動前のY座標。足場の上面をまたいだかの判定に使う。
    float previousY = 696.0f;
    // 縦の速度。マイナスなら上昇、プラスなら落下。
    float velocityY = 0.0f;
    // 描画領域には余白があるため、見える靴底を足元とする
    static constexpr float FootOffset = 82.0f;
    int PushCount = 0;     // ためた時間（ミリ秒）
    // キーを押し始めた時刻をミリ秒で保存する。
    int PushStartTime = 0;
    // ジャンプをためている間だけtrueになる。
    bool isCharging = false;
    // 足場に乗っているならtrue、空中ならfalse。
    bool onGround = true;
    // 画像そのものではなく管理番号。-1は有効な画像がないことを表す。
    int imageHandle = -1;
// ほかのクラスから呼び出せる関数など。
public:
    // 画像などを読み込む処理。voidは戻り値を返さないという意味。
    void Load();
    // 画面に描く処理。移動の計算とは分けている。
    void Draw();
    // 時間経過や入力に応じて状態を更新する処理。
    void Update();
    void UpdateAnimation();
    // 引数left・right・topは足場の左端・右端・上端。上から着地するか調べる。
    void CheckLanding(float left, float right, float top);
};