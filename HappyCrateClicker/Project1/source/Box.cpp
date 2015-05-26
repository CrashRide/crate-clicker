#include "Box.h"


Box::Box(Vector2 &b_topLeft, Vector2 &b_bottomRight)
{
	b_tl = new Vector2(b_topLeft);
	b_br = new Vector2(b_bottomRight);
}


Box::~Box()
{
	delete b_br;
	delete b_tl;
}

bool Box::ClickWithinBox(int &mouseX, int &mouseY)
{
	Vector2 tempMouse((float)mouseX, (float)mouseY);
	if (tempMouse > *b_tl && tempMouse < *b_br)
		return true;
	else
		return false;
}
