#include "Inventory.h"



Inventory::Inventory(sf::Vector2i pos, sf::Vector2i size, const int nrofSlots, const int cols, const int rows){
	_debugColor = sf::Color::White;
	_position = static_cast<sf::Vector2f>(pos);
	_width = size.x;
	_height = size.y;
	_separation = sf::Vector2i(4, 4);
	_cols = cols;
	_rows = rows;
	for (int i = 0; i < nrofSlots; i++) {
		ItemSlot slot;
		_itemSlots.push_back(slot);
	}
	initSlots(_itemSlots, pos, sf::Vector2i(size.x / _cols - _separation.x + _separation.x / (_cols - 1), size.y / _rows - _separation.y + _separation.y / (_rows - 1)), _separation, _cols, _rows);
}

Inventory::~Inventory(){

}

std::vector<ItemSlot>& Inventory::slots() {
	return _itemSlots;
}

void Inventory::debugDraw(sf::RenderWindow& window) {
	for (auto& slot : _itemSlots) {
		slot.debugDraw(window);
	}
	BoundingRect::debugDraw(window);
}