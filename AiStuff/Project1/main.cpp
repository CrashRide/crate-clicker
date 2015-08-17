
#include "Game2.h"

// DEBUG
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>

	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
		#define new DBG_NEW
	#endif
#endif

int main(int argc, char **argv)
{
	{
		Game2 *pGame = new Game2(1440, 720, false, "Graph Creator");
		pGame->RunGame();
		delete pGame;
	}
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	return 0;

};