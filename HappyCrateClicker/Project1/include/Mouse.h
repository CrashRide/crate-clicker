#ifndef _MOUSE_H_
#define _MOUSE_H_
#include "Upgrade.h"
#include <Windows.h>

class Mouse
{
public:

	Mouse();
	~Mouse();

	int GetX();
	int GetY();

	float m_power;

private:

	int m_posX;
	int m_posY;	

};

#endif