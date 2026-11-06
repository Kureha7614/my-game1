#pragma once
class Animation
{
private:
	int currentFrame = 0;  // 現在のコマ番号
	int frameCount = 1;    // 使用するコマ数
	int frameTimer = 0;    // 更新回数を数える
	int frameInterval = 32; // 32回更新したら次のコマへ
public:
	void Update();
	void Reset();
	int GetCurrentFrame() const;
	void SetFrameCount(int count);
};