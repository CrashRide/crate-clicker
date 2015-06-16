#include "Upgrade.h"

Upgrade::Upgrade()
{
	u_modifier = NULL;
	u_operation = NULL;
	u_name = new char[64];
	u_name[0] = NULL;
	u_cost = NULL;
	u_id = -1;
	u_mouseModifier = NULL;
}

Upgrade::Upgrade(float a_mod, char a_op, int a_cost, char a_name[])
{
	u_modifier = a_mod;
	u_operation = a_op;
	u_id = -1;
	u_cost = a_cost;
	u_mouseModifier = NULL;
	u_name = new char[strlen(a_name) + 1];
	for (unsigned int i = 0; i < strlen(a_name); i++)
	{
		u_name[i] = a_name[i];
	}
	u_name[strlen(a_name)] = NULL;
}

Upgrade::Upgrade(float a_mouseMod, float a_cursorMod, char a_op, int a_cost, char a_name[])
{
	u_modifier = a_cursorMod;
	u_operation = a_op;
	u_id = -1;
	u_cost = a_cost;
	u_mouseModifier = a_mouseMod;
	u_name = new char[strlen(a_name) + 1];
	for (unsigned int i = 0; i < strlen(a_name); i++)
	{
		u_name[i] = a_name[i];
	}
	u_name[strlen(a_name)] = NULL;
}


Upgrade::~Upgrade()
{
	delete[] u_name;
}

float Upgrade::GetMod()
{
	return u_modifier;
}

float Upgrade::GetMouseMod()
{
	return u_mouseModifier;
}

char Upgrade::GetOp()
{
	return u_operation;
}

char* Upgrade::GetName()
{
	return u_name;
}

int Upgrade::GetCost()
{
	return u_cost;
}
