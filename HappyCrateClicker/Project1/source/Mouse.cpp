#include "Mouse.h"


Mouse::Mouse()
{
	m_power = 1.0f;
	m_posX = -1;
	m_posY = -1;
}


Mouse::~Mouse()
{
}

int Mouse::GetX()
{
	//POINT p;
	//CONSOLE_FONT_INFO tempfont;
	//CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	//HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//GetConsoleScreenBufferInfo(hStdout, &screenBufferInfo);
	//CONSOLE_FONT_INFO cfi;
	//BOOL bFont = GetCurrentConsoleFont(hStdout, 0, &cfi);
	//cfi.dwFontSize = GetConsoleFontSize(hStdout, cfi.nFont);
	//HWND hWnd = GetConsoleWindow();
	//int fx, fy;
	//fx = cfi.dwFontSize.X;
	//fy = cfi.dwFontSize.Y;
	//GetCursorPos(&p);
	//ScreenToClient(hWnd, &p);
	//int x = p.x;
	//int y = p.y;
	////--for console mode
	//int row, col;
	//row = (int)x / fx;
	//col = (int)y / fy;
	//m_posX = row;
	return m_posX;
}

int Mouse::GetY()
{
	//POINT p;
	//CONSOLE_FONT_INFO tempfont;
	//CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	//HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//GetConsoleScreenBufferInfo(hStdout, &screenBufferInfo);
	//CONSOLE_FONT_INFO cfi;
	//BOOL bFont = GetCurrentConsoleFont(hStdout, 0, &cfi);
	//cfi.dwFontSize = GetConsoleFontSize(hStdout, cfi.nFont);
	//HWND hWnd = GetConsoleWindow();
	//int fx, fy;
	//fx = cfi.dwFontSize.X;
	//fy = cfi.dwFontSize.Y;
	//GetCursorPos(&p);
	//ScreenToClient(hWnd, &p);
	//int x = p.x;
	//int y = p.y;
	////--for console mode
	//int row, col;
	//row = (int)x / fx;
	//col = (int)y / fy;
	//m_posY = col;
	return m_posY;
}
