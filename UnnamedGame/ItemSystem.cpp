#include "ItemSystem.h"


ItemSystem::ItemSystem(sf::RenderWindow &window, Inventory& inventory, std::vector<Item*>& items) :
	_window(window),
	_inventory(inventory),
	_items(items),
	_mouseData(window, inventory, items){

}

ItemSystem::~ItemSystem(){

}

void ItemSystem::updateItemPos() {
	for (auto &slot : _inventory.slots()) {
		if (slot.item() == nullptr) {
			continue;
		}
		slot.item()->setPos(slot.pos());
		int test = 0;
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