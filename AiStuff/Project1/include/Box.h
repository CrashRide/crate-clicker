#ifndef _BOX_H_
#define _BOX_H_
#include "MathLib.h"
using namespace MathLib;

class Box
{
public:
	Box(Vector2 &b_topLeft, Vector2 &b_bottomRight);
	~Box();

	bool LineCollision(Vector2 p0, Vector2 p1);
	//bool BoxCollision(Box a_box);
	bool ClickWithinBox(int &mouseX, int &mouseY);

private:
	Vector2 b_tl;
	Vector2 b_br;
};

#endif