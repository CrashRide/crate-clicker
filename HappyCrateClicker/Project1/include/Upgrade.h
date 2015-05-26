#ifndef _UPGRADE_H_
#define _UPGRADE_H_
#include <iostream>

class Upgrade
{
public:

	Upgrade();
	Upgrade(float a_mod, char a_op, int a_cost, char a_name[]);
	Upgrade(float a_mouseMod, float a_cursorMod, char a_op, int a_cost, char a_name[]);
	~Upgrade();

	float GetMod();
	float GetMouseMod();
	char GetOp();
	char* GetName();
	int GetCost();

	int u_id;
	
private:

	float u_modifier;
	float u_mouseModifier;
	char u_operation;
	int u_cost;
	char * u_name;

};

#endif