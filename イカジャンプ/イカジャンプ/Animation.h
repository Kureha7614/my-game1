// このヘッダーを同じソース内で何度も読み込まないための指定。
#pragma once
// 関連するデータと処理をまとめるクラス。
class Animation
{
// このクラスの内部から使う変数や型。
private:
	int currentFrame = 0;  // 現在のコマ番号
	int frameCount = 1;    // 使用するコマ数
	int frameTimer = 0;    // 更新回数を数える
	int frameInterval = 32; // 32回更新したら次のコマへ
// ほかのクラスから呼び出せる関数など。
public:
	// 時間経過や入力に応じて状態を更新する処理。
	void Update();
	// コマ番号とタイマーを戻し、最初から再生できるようにする。
	void Reset();
	// 現在のコマ番号をintで返す。末尾のconstはオブジェクトの状態を変えない指定。
	int GetCurrentFrame() const;
	// 引数で受け取ったコマ数を設定する。1以上の数を渡して使う。
	void SetFrameCount(int count);
    // 次のコマまで待つ更新回数を、引数で受け取って設定する。
    void SetFrameInterval(int interval);
};