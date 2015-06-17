
#include "Game1.h"


int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(1280, 720, false, "Crate Clicker");
	pGame->RunGame();
	delete pGame;

	return 0;
};