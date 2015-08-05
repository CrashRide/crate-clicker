#include "Box.h"
#include "MathLib.h"
using namespace MathLib;

Box::Box(Vector2 &b_topLeft, Vector2 &b_bottomRight)
{
	b_tl = Vector2(b_topLeft);
	b_br = Vector2(b_bottomRight);
}


Box::~Box()
{

}

bool Box::LineCollision(Vector2 p0, Vector2 p1)
{

	for (float t = 0.0f; t <= 1.0f; t += 0.05f)
	{
		Vector2 temp = p0 + (t * (p1 - p0));
		if (temp > b_tl)
		{
			if (temp < b_br)
				return true;
		}
	}

	return false;

}

bool Box::ClickWithinBox(int &mouseX, int &mouseY)
{
	Vector2 tempMouse((float)mouseX, (float)mouseY);
	if (tempMouse > b_tl && tempMouse < b_br)
		return true;
	else
		return false;
}
