#include "Game.h"

int main(int argc, char* args[])
{
	Game *game = new Game();
	game->Initialize();
	game->Start();
	return 0;
}