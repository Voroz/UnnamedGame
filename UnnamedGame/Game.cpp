#include "Game.h"



Game::Game(){

}

Game::~Game(){

}

void Game::run() {
	std::vector<Item*> items;
	items.push_back(new Item);
	items.push_back(new Item);

	Inventory inventory(sf::Vector2i(560, 400), sf::Vector2i(212, 158), 12, 4, 3);

	inventory.slots()[0].assignItem(*items[0]);
	inventory.slots()[1].assignItem(*items[1]);

	items[0]->setWidth(50);
	items[0]->setHeight(50);
	items[1]->setWidth(50);
	items[1]->setHeight(50);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Item System");

	ItemSystem itemSystem(window, inventory, items);

	// run the program as long as the window is open
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		itemSystem.tick();

		window.clear();
		inventory.debugDraw(window);
		for (auto& item : items) {
			item->debugDraw(window);
		}
		window.display();
	}

	// Delete allocated item memory before closing
	for (auto item : items) {
		delete item;
	}
}