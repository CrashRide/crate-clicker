#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>
#include "Buildings.h"
#include "Shop.h"
using namespace std;

string DrawColorString(string szText, WORD color)
{
	HANDLE OutputH;
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(OutputH, color);
	return szText;
}

void gotoXY(int x, int y)
{
	//Initialize the coordinates
	COORD coord = { x, y };
	//Set the position
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void ClearConsole()
{
	//Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//This is used to reset the carat/cursor to the top left.
	COORD coord = { 0, 0 };
	//A return value... indicating how many chars were written
	//   not used but we need to capture this since it will be
	//   written anyway (passing NULL causes an access violation).
	DWORD count;
	//This is a structure containing all of the console info
	// it is used here to find the size of the console.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//Here we will set the current color
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//This fills the buffer with a given character (in this case 32=space).
		FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		//This will set our cursor position for the next print statement.
		SetConsoleCursorPosition(hStdOut, coord);
	}
	return;
}

void Display(float* count, float* cps, Shop& a_shop, Buildings a_cursor, Buildings a_grandma, Buildings a_farm, Buildings a_factory, Buildings a_mine, Buildings a_shipment, Buildings a_alchemy, Buildings a_portal, Buildings a_timeMachine)
{
	//Displays the ui and my fancy ass ASCII cookie
	system("cls");

	*cps = (a_cursor.GetCPS() + a_grandma.GetCPS() + a_farm.GetCPS() + a_factory.GetCPS() + a_mine.GetCPS() + a_shipment.GetCPS() + a_alchemy.GetCPS() + a_portal.GetCPS() + a_timeMachine.GetCPS());
	const char c = 184;
	cout << DrawColorString("", FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) << "			COOKIE CLICKER: CONSOLE EDITION			       " << endl;
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "				|	UPGRADES	|	BUILDINGS" << endl;
	cout << "	 [QUIT GAME]		|_______________________|______________________" << endl;
	cout << "				|	" << a_shop[0].GetName() << "		| Own: " << a_cursor.GetCount() << " Cursors" << endl;
	cout << "				|	";
	if (a_shop[0].GetCost() != NULL)
	{
		cout << a_shop[0].GetCost();
	}
	cout << "		| Cost: " << a_cursor.GetCost() << " " << c << "'s" << endl;
	cout << "				|_______________________|______________________" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	   -------";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|	" << a_shop[1].GetName() << "		| Own: " << a_grandma.GetCount() << " Grandmas" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	 /..*...*..\\";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|	";
	if (a_shop[1].GetCost() != NULL)
	{
		cout << a_shop[1].GetCost();
	}
	cout << "		| Cost: " << a_grandma.GetCost() << " " << c << "'s" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	,,,,......,,,";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|_______________________|______________________" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	|*,,.,*.,..,|";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|	" << a_shop[2].GetName() << "		| Own: " << a_farm.GetCount() << " Farms" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	|,.,,,.*,.*.|";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|	";
	if (a_shop[2].GetCost() != NULL)
	{
		cout << a_shop[2].GetCost();
	}
	cout << "		| Cost: " << a_farm.GetCost() << " " << c << "'s" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	',*,.,.,,.,,'";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|_______________________|______________________" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	 \\..*...*../";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|	" << a_shop[3].GetName() << "		| Own: " << a_factory.GetCount() << " Factories" << endl;
	cout << DrawColorString("", FOREGROUND_RED | FOREGROUND_GREEN) << "	   -------";
	cout << DrawColorString("", FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) << "		|	";
	if (a_shop[3].GetCost() != NULL)
	{
		cout << a_shop[3].GetCost();
	}
	cout << "		| Cost: " << a_factory.GetCost() << " " << c << "'s" << endl;
	cout << "				|_______________________|______________________" << endl;
	cout << "				|	" << a_shop[4].GetName() << "		| Own: " << a_mine.GetCount() << " Mines" << endl;
	cout << "	 Cookies: ";
	printf("%.1f", *count);
	cout << "		|	";
	if (a_shop[4].GetCost() != NULL)
	{
		cout << a_shop[4].GetCost();
	}
	cout << "		| Cost: " << a_mine.GetCost() << " " << c << "'s" << endl;
	cout << "	 			|_______________________|______________________" << endl;
	cout << "	   CPS: " << *cps << "		|	" << a_shop[5].GetName() << "		| Own: " << a_shipment.GetCount() << " Shipments" << endl;
	cout << "				|	";
	if (a_shop[5].GetCost() != NULL)
	{
		cout << a_shop[5].GetCost();
	}
	cout << "		| Cost: " << a_shipment.GetCost() << " " << c << "'s" << endl;
	cout << "				|_______________________|______________________" << endl;
	cout << "				|	" << a_shop[6].GetName() << "		| Own: " << a_alchemy.GetCount() << " Alchemy Labs" << endl;
	cout << "				|	";
	if (a_shop[6].GetCost() != NULL)
	{
		cout << a_shop[6].GetCost();
	}
	cout << "		| Cost: " << a_alchemy.GetCost() << " " << c << "'s" << endl;
	cout << "				|_______________________|______________________" << endl;
	cout << "				|	" << a_shop[7].GetName() << "		| Own: " << a_portal.GetCount() << " Portals" << endl;
	cout << "				|	";
	if (a_shop[7].GetCost() != NULL)
	{
		cout << a_shop[7].GetCost();
	}
	cout << "		| Cost: " << a_portal.GetCost() << " " << c << "'s" << endl;
	cout << " ______________________________	|_______________________|______________________" << endl;
	cout << "|	Tooltip Area:	       ||	" << a_shop[8].GetName() << "		| Own: " << a_timeMachine.GetCount() << " Time Machines" << endl;
	cout << "|			       ||	";
	if (a_shop[8].GetCost() != NULL)
	{
		cout << a_shop[8].GetCost();
	}
	cout << "		| Cost: " << a_timeMachine.GetCost() << " " << c << "'s" << endl;
	cout << "|______________________________||_______________________|______________________" << endl;
}

char ClickInput(Mouse playerMouse)
{
	if (playerMouse.GetX() > 7 && playerMouse.GetX() < 21 && playerMouse.GetY() > 5 && playerMouse.GetY() < 13)
		return 'C';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 2 && playerMouse.GetY() < 6)
		return 'K';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 5 && playerMouse.GetY() < 9)
		return 'G';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 8 && playerMouse.GetY() < 12)
		return 'B';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 11 && playerMouse.GetY() < 15)
		return 'F';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 14 && playerMouse.GetY() < 18)
		return 'M';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 17 && playerMouse.GetY() < 21)
		return 'S';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 20 && playerMouse.GetY() < 24)
		return 'A';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 23 && playerMouse.GetY() < 27)
		return 'P';
	else if (playerMouse.GetX() > 56 && playerMouse.GetX() < 80 && playerMouse.GetY() > 26 && playerMouse.GetY() < 30)
		return 'T';
	else if (playerMouse.GetX() > 8 && playerMouse.GetX() < 20 && playerMouse.GetY() == 2)
		return 'Q';
	else
		return NULL;
}

void CPS(float* cps, float* count, chrono::time_point<chrono::system_clock>* begin)
{
	chrono::time_point<chrono::system_clock> end = chrono::system_clock::now();

	chrono::duration<double> diff = (end - *begin) * 1000.0;
	int diff2 = diff.count();
	if (diff2 % 999 == 0)
	{
		*count += *cps;
		Sleep(1);
	}
}

int main()
{

	/*clock_t t = clock();
	clock_t* start = &t;*/

	chrono::time_point<chrono::system_clock> t = chrono::system_clock::now();
	chrono::time_point<chrono::system_clock>* start = &t;

	Buildings Cursor(0.1f, 15);
	Buildings Grandma(0.5f, 100);
	Buildings Farm(4, 500);
	Buildings Factory(10, 3000);
	Buildings Mine(40, 10000);
	Buildings Shipment(100, 40000);
	Buildings AlchemyLab(400, 200000);
	Buildings Portal(6666, 1666666);
	Buildings TimeMachine(98765, 123456789);

	Mouse playerMouse;

	Shop shop(50);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 420, TRUE);

	bool quit = false;

	float cookieCount = 0.0;
	float* pCookieCount = &cookieCount;
	float cps = (Cursor.GetCPS() + Grandma.GetCPS() + Farm.GetCPS() + Factory.GetCPS() + Mine.GetCPS() + Shipment.GetCPS() + AlchemyLab.GetCPS() + Portal.GetCPS() + TimeMachine.GetCPS());
	float* pCps = &cps;
	Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);

	/*while (true)
	{
	system("cls");
	Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);

	cout << playerMouse.GetX() << " , " << playerMouse.GetY();
	Sleep(100);
	}*/

	while (!quit)
	{
		CPS(pCps, pCookieCount, start);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			Sleep(1);
			CPS(pCps, pCookieCount, start);
			if (!GetAsyncKeyState(VK_LBUTTON))
			{
				switch (ClickInput(playerMouse))
				{
				case 'C':
				{
							*pCookieCount += playerMouse.m_power;
							break;
				}
				case 'K':
				{
							if (*pCookieCount >= Cursor.GetCost())
							{
								*pCookieCount -= Cursor.GetCost();
								Cursor.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'G':
				{
							if (*pCookieCount >= Grandma.GetCost())
							{
								*pCookieCount -= Grandma.GetCost();
								Grandma.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'B':
				{
							if (*pCookieCount >= Farm.GetCost())
							{
								*pCookieCount -= Farm.GetCost();
								Farm.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'F':
				{
							if (*pCookieCount >= Factory.GetCost())
							{
								*pCookieCount -= Factory.GetCost();
								Factory.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'M':
				{
							if (*pCookieCount >= Mine.GetCost())
							{
								*pCookieCount -= Mine.GetCost();
								Mine.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'S':
				{
							if (*pCookieCount >= Shipment.GetCost())
							{
								*pCookieCount -= Shipment.GetCost();
								Shipment.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'A':
				{
							if (*pCookieCount >= AlchemyLab.GetCost())
							{
								*pCookieCount -= AlchemyLab.GetCost();
								AlchemyLab.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'P':
				{
							if (*pCookieCount >= Portal.GetCost())
							{
								*pCookieCount -= Portal.GetCost();
								Portal.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'T':
				{
							if (*pCookieCount >= TimeMachine.GetCost())
							{
								*pCookieCount -= TimeMachine.GetCost();
								TimeMachine.Purchase();
								Display(pCookieCount, pCps, shop, Cursor, Grandma, Farm, Factory, Mine, Shipment, AlchemyLab, Portal, TimeMachine);
							}
							break;
				}
				case 'Q':
				{
							quit = true;
							break;
				}
				default:
				{
						   CPS(pCps, pCookieCount, start);
						   break;
				}
				}
			}
		}
		else
		{
			gotoXY(6, 28);
			switch (ClickInput(playerMouse))
			{
			case 'C':
			{
						cout << playerMouse.m_power << " cookies per click.";
						break;
			}
			case 'K':
			{
						cout << "Gives +" << Cursor.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'G':
			{
						cout << "Gives +" << Grandma.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'B':
			{
						cout << "Gives +" << Farm.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'F':
			{
						cout << "Gives +" << Factory.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'M':
			{
						cout << "Gives +" << Mine.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'S':
			{
						cout << "Gives +" << Shipment.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'A':
			{
						cout << "Gives +" << AlchemyLab.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'P':
			{
						cout << "Gives +" << Portal.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'T':
			{
						cout << "Gives +" << TimeMachine.GetBaseCPS() << " CPS.	";
						break;
			}
			case 'Q':
			{
						cout << "Quit the game.";
						break;
			}
			default:
			{
					   CPS(pCps, pCookieCount, start);
					   cout << "			       ";
					   break;
			}
			}
		}
		CPS(pCps, pCookieCount, start);
		if (clock() % 25 == 0)
		{
			gotoXY(18, 16);
			printf("%.1f      ", cookieCount);
		}
	}
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
	return 0;
}
