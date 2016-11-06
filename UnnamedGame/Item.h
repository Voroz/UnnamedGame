#pragma once
#include "BoundingRect.h"
#include "Inventory.h"

enum ItemLocation {
	LInventory,
	LWorld,
};

class Inventory;

class Item : public BoundingRect
{
public:
	Item(sf::Vector2i coords);
	Item(Inventory& inventory);
	~Item();

private:
	ItemLocation _location;
};

