#ifndef _SHOP_H_
#define _SHOP_H_
#include "Upgrade.h"

class Shop
{
public:

	Shop(int size);
	~Shop();

	void AddUpg(Upgrade &a_upgd);
	void DeleteUpg(Upgrade &a_upgd);

	Upgrade& operator[](int a_index);

private:

	Upgrade* shopInv;
	int invSize;

};

#endif