#include "Game.h"

void Game::Load()
{
	background.Load();
	ground.Load();
	character.Load();
}

void Game::Draw()
{
	background.Draw();
	ground.Draw();
	character.Draw();
}

void Game::Update()
{
	character.Update();
}
