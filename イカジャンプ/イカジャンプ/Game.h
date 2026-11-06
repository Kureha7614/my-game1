// このヘッダーを同じソース内で何度も読み込まないための指定。
#pragma once
// このファイルで使うクラスや関数の宣言を読み込む。
#include"DxLib.h"
// このファイルで使うクラスや関数の宣言を読み込む。
#include"BackGround.h"
// このファイルで使うクラスや関数の宣言を読み込む。
#include"Ground.h"
// このファイルで使うクラスや関数の宣言を読み込む。
#include"Character.h"
// 関連するデータと処理をまとめるクラス。
class Game
{
// このクラスの内部から使う変数や型。
private:
	BackGround background;
	Ground ground;
	Character character;
// ほかのクラスから呼び出せる関数など。
public:
	enum Titol
	{
		Gametitol,
		GameScene,
		GameOver
	};
	// 画像などを読み込む処理。voidは戻り値を返さないという意味。
	void Load();
	// 画面に描く処理。移動の計算とは分けている。
	void Draw();
	// 時間経過や入力に応じて状態を更新する処理。
	void Update();
};

