#include "Game.h"

void Game::Load()
{
	background.Load();
	character.Load();
	ground.Load();
	character.Load();
}

void Game::Draw()
{
	background.Draw();
	character.Draw();
	ground.Draw();
	character.Draw();
}

void Game::Update()
{

}
