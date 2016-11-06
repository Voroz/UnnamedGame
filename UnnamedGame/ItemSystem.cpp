#include "ItemSystem.h"


ItemSystem::ItemSystem(sf::RenderWindow &window, Inventory& inventory) :
	_window(window),
	_inventory(inventory),
	_mouseData(window, inventory, _items){

}

ItemSystem::~ItemSystem(){
	for (auto& item : _items) {
		delete item;
	}
}

ItemSlot* ItemSystem::findFirstFreeSlot(Inventory& inventory){
	ItemSlot* currSlot = nullptr;
	for (auto& slot : inventory.slots()) {
		if (slot.item() == nullptr) {
			currSlot = &slot;
		}
	}
	if (currSlot == nullptr) {
		return nullptr;
	}
	for (auto& slot : inventory.slots()) {
		// slot already has item, continue.
		if (slot.item() != nullptr) {
			continue;
		}
		if (slot.pos().x < currSlot->pos().x) {
			currSlot = &slot;
			continue;
		}
		if (slot.pos().x == currSlot->pos().x && slot.pos().y < currSlot->pos().y) {
			currSlot = &slot;
			continue;
		}
	}
	return currSlot;
}

// Temporary implementation (Can't choose type of item to spawn yet).
void ItemSystem::spawnItem(Inventory& inventory) {
	ItemSlot* slot = findFirstFreeSlot(inventory);
	if (slot == nullptr) {
		return;
	}
	_items.push_back(new Item(inventory));
	_items.back()->setWidth(slot->width());
	_items.back()->setHeight(slot->height());
	slot->assignItem(*_items.back());
}
std::vector<Item*>& ItemSystem::items() {
	return _items;
}
void ItemSystem::updateItemPos() {
	for (auto &slot : _inventory.slots()) {
		if (slot.item() == nullptr) {
			continue;
		}
		slot.item()->setPos(slot.pos());
	}
}
void ItemSystem::tick() {
	updateItemPos();
	_mouseData.update();

	// Move around items in inventory slots
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (_mouseData.mouseLeftClickedThisFrame) {
			_moveItemData.from = _mouseData.mouseOverSlot;
		}
		if (_mouseData.leftButtonDraggedDistance >= 6) {
			// Set dragging to true and find which slot is being dragged from
			if (_moveItemData.dragging == false) {
				_moveItemData.dragging = true;
			}
			// Set position of icon to mouse pos
			if (_moveItemData.from != nullptr && _moveItemData.from->item() != nullptr) {
				Item* item = _moveItemData.from->item();
				item->setPos(_mouseData.position.x - item->width() / 2, _mouseData.position.y - item->height() / 2);
			}
		}
	}
	else{
		// Mouse released, set dragging to false and attempt item swap
		if (_moveItemData.dragging == true) {
			_moveItemData.dragging = false;
			if (_moveItemData.from != nullptr && _moveItemData.from->item() != nullptr) {
				_moveItemData.to = _mouseData.mouseOverSlot;
				moveItem(_moveItemData.from, _moveItemData.to);
			}
		}
	}
}