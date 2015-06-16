#include "Buildings.h"

Buildings::Buildings(float a_cps, int a_cost)
{
	b_cost = a_cost;
	b_count = 0;
	b_baseCps = a_cps;
	b_cumulitiveCps = b_baseCps * b_count;
	b_baseCost = b_cost;
}


Buildings::~Buildings()
{
}

void Buildings::Purchase()
{
	b_count++;
	b_cumulitiveCps = b_baseCps * b_count;
	float temp = 1.15f;
	for (int i = 1; i < b_count; i++)
	{
		temp *= 1.15f;
	}
	b_cost = (int)(b_baseCost * temp);
}

void Buildings::Upg(Upgrade &a_upgd)
{
	if (a_upgd.GetOp() == '+')
		b_baseCps += a_upgd.GetMod();
	else if (a_upgd.GetOp() == '*')
		b_baseCps *= a_upgd.GetMod();
}

void Buildings::MouseCursorUpg(Upgrade &a_upgd, Mouse &a_mouse)
{
	if (a_upgd.GetOp() == '+')
	{
		b_baseCps += a_upgd.GetMod();
		a_mouse.m_power += a_upgd.GetMouseMod();
	}
	else if (a_upgd.GetOp() == '*')
	{
		b_baseCps *= a_upgd.GetMod();
		a_mouse.m_power *= a_upgd.GetMouseMod();
	}
}

float Buildings::GetCPS()
{
	return b_cumulitiveCps;
}
float Buildings::GetBaseCPS()
{
	return b_baseCps;
}

int Buildings::GetCount()
{
	return b_count;
}

int Buildings::GetCost()
{
	return b_cost;
}
