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

bool Box::VectorWithinBox(Vector2 a_vec)
{

	if (a_vec > this->b_tl && a_vec < this->b_br)
		return true;
	else
		return false;

}

bool Box::BoxCollision(Box a_box)
{

	if (VectorWithinBox(a_box.b_tl) || VectorWithinBox(a_box.b_br))
		return true;
	else if (VectorWithinBox(Vector2(a_box.b_tl.x, a_box.b_br.y)) || VectorWithinBox(Vector2(a_box.b_br.x, a_box.b_tl.y)))
		return true;
	else
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
