#pragma once
#include "BoundingRect.h"
#include "Item.h"

class ItemSlot :
	public BoundingRect{

public:
	ItemSlot();
	~ItemSlot();
	Item* item();
	void assignItem(Item& item);

private:
	Item* _item;
};

