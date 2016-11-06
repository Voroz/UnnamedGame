#pragma once
#include "ItemManip.h"

class Inventory : public BoundingRect
{
public:
	Inventory(sf::Vector2i pos, sf::Vector2i size, const int nrofSlots, const int cols, const int rows);
	~Inventory();

	std::vector<ItemSlot>& slots();
	void debugDraw(sf::RenderWindow& window);

private:
	std::vector<ItemSlot> _itemSlots;
	sf::Vector2i _separation;
	int _cols;
	int _rows;
};

