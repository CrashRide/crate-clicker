#include "Shop.h"


Shop::Shop(int size)
{
	invSize = size;
	shopInv = new Upgrade[invSize];
}


Shop::~Shop()
{
	delete[] shopInv;
}

void Shop::AddUpg(Upgrade &a_upgd)
{
	for (int i = 0; i < invSize; i++)
	{
		if (shopInv[i].u_id = -1)
		{
			shopInv[i] = a_upgd;
			shopInv[i].u_id = i;
			i = invSize;
		}
	}
}

void Shop::DeleteUpg(Upgrade &a_upgd)
{
	for (int i = a_upgd.u_id; i < invSize - 1; i++)
	{
		shopInv[i] = shopInv[i + 1];
	}
	shopInv[invSize - 1] = Upgrade();
}

Upgrade& Shop::operator[](int a_index)
{
	return shopInv[a_index];
}
