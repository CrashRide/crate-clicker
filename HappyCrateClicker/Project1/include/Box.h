#ifndef _BOX_H_
#define _BOX_H_
#include "MathLib.h"
using namespace MathLib;

class Box
{
public:
	Box(Vector2 &b_topLeft, Vector2 &b_bottomRight);
	~Box();

	bool ClickWithinBox(int &mouseX, int &mouseY);

private:
	Vector2* b_tl;
	Vector2* b_br;
};

#endif