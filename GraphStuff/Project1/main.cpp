
#include "Game1.h"

// DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char **argv)
{
	{
		Game1 *pGame = new Game1(1440, 720, false, "Graph Creator");
		pGame->RunGame();
		delete pGame;
	}

	_CrtDumpMemoryLeaks();

	return 0;

};