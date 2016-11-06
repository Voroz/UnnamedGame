#pragma once
#include "ItemSlot.h"
#include "ItemManip.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <array>

struct MoveItemData {
	ItemSlot* from = nullptr;
	ItemSlot* to = nullptr;
	bool dragging = false;
};

class MouseData {
public:
	MouseData(sf::RenderWindow &window, Inventory& inventory, std::vector<Item*>& items) :
		_window(window),
		_inventory(inventory),
		_items(items){

	}
	~MouseData() {

	}
	void update() {
		position = sf::Mouse::getPosition(_window);
		mouseLeftClickedThisFrame = !_mouseDownLastFrame;
		
		mouseOverSlot = nullptr;
		for (auto &slot : _inventory.slots()) {
			if (slot.contains(static_cast<sf::Vector2f>(position))) {
				mouseOverSlot = &slot;
				break;
			}
		}

		mouseOverItem = nullptr;
		for (auto &item : _items) {
			if (item->contains(static_cast<sf::Vector2f>(position))) {
				mouseOverItem = item;
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mouseTraveledDistance = position - _previousPos;
			float x = mouseTraveledDistance.x;
			float y = mouseTraveledDistance.y;
			leftButtonDraggedDistance += sqrt(x*x + y*y);
		}
		else {
			leftButtonDraggedDistance = 0;
		}
		mouseOnInventory = _inventory.contains(static_cast<sf::Vector2f>(position));
		_previousPos = position;
		_mouseDownLastFrame = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	sf::Vector2i position;
	float leftButtonDraggedDistance = 0;
	ItemSlot* mouseOverSlot = nullptr;
	Item* mouseOverItem = nullptr;
	bool mouseOnInventory = false;
	bool mouseLeftClickedThisFrame = false;

private:
	sf::RenderWindow &_window;
	Inventory& _inventory;
	std::vector<Item*>& _items;
	sf::Vector2i _previousPos = sf::Mouse::getPosition(_window);
	bool _mouseDownLastFrame = false;
};

class ItemSystem
{
public:
	ItemSystem(sf::RenderWindow &window, Inventory& inventory, std::vector<Item*>& items);
	~ItemSystem();
	void updateItemPos();
	void tick();

private:
	MoveItemData _moveItemData;
	MouseData _mouseData;
	sf::RenderWindow &_window;
	Inventory& _inventory;
	std::vector<Item*>& _items;
};

