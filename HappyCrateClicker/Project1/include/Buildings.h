#ifndef _BUILDINGS_H_
#define _BUILDINGS_H_
#include "Upgrade.h"
#include "Mouse.h"

class Buildings
{
public:

	Buildings(float a_cps, int a_cost);
	~Buildings();

	void Purchase();
	void Upg(Upgrade &a_upgd);
	void MouseCursorUpg(Upgrade &a_upgd, Mouse &a_mouse);
	float GetCPS();
	float GetBaseCPS();
	int GetCount();
	int GetCost();

private:

	float b_baseCps;
	float b_cumulitiveCps;
	int b_count;
	int b_cost;
	int b_baseCost;

};

#endif