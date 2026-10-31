#pragma once
class Character
{
private:
	enum class State
	{
		Idle,//待機
		Run,//走る
		Jump,//ジャンプ
		Fall//落下中
	};
	State state = State::Idle;
	//ぷれいやーの座標
	int playerX = 200;
	// 地面画像の上側の余白と、キャラ画像の足元の位置を考慮した開始位置
	int playerY = 696;
	int PushCount = 0;//どのくらい押したか
	int PushStartTime = 0;//押し始めた時間
	bool isCharging = false;
	int imageHandle = -1;
public:
	void Load();
	void Draw();
	void Update();
};

