// このファイルで使うクラスや関数の宣言を読み込む。
#include "Game.h"

// 画像などを読み込む処理。voidは戻り値を返さないという意味。
void Game::Load()
{
	background.Load();
	ground.Load();
	character.Load();
}

// 画面に描く処理。移動の計算とは分けている。
void Game::Draw()
{
	background.Draw();
	ground.Draw();
	character.Draw();
}

// 時間経過や入力に応じて状態を更新する処理。
void Game::Update()
{
	character.Update();
	character.CheckLanding(ground.GetLeft(), ground.GetRight(), ground.GetTop());
    character.UpdateAnimation();
}
