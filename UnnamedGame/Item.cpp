#include "Item.h"



Item::Item(sf::Vector2i coords) :
	_location(ItemLocation::LWorld){
	_debugColor = sf::Color::Green;
}
Item::Item(Inventory& inventory) :
	_location(ItemLocation::LInventory) {
	_debugColor = sf::Color::Blue;

}

Item::~Item(){

}
