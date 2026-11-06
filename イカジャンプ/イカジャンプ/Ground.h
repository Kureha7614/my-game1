// このヘッダーを同じソース内で何度も読み込まないための指定。
#pragma once
// このファイルで使うクラスや関数の宣言を読み込む。
#include"DxLib.h"
// 関連するデータと処理をまとめるクラス。
class Ground
{
// このクラスの内部から使う変数や型。
private:
	int width = 200;
	int height = 100;
	int x = 140;
	int y = 750;
	// 画像そのものではなく管理番号。-1は有効な画像がないことを表す。
	int imageHandle = -1;
// ほかのクラスから呼び出せる関数など。
public:
	// 画像などを読み込む処理。voidは戻り値を返さないという意味。
	void Load();
	// 画面に描く処理。移動の計算とは分けている。
	void Draw();
	float GetLeft() const { return static_cast<float>(x); }
	float GetRight() const { return static_cast<float>(x + width); }
	// 画像上端から約28%は透明な余白
	float GetTop() const { return y + height * 0.28f; }
};

