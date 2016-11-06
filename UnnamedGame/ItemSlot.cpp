#include "ItemSlot.h"



ItemSlot::ItemSlot() : 
	_item(nullptr){

}

ItemSlot::~ItemSlot(){

}

Item* ItemSlot::item() {
	return _item;
}

void ItemSlot::assignItem(Item& item) {
	_item = &item;
}