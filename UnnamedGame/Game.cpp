#include "Game.h"



Game::Game(){

}

Game::~Game(){

}

void Game::run() {
	Character character;
	Inventory inventory(sf::Vector2i(560, 400), sf::Vector2i(212, 158), 12, 4, 3);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Item System");

	ItemSystem itemSystem(window, inventory);
	itemSystem.spawnItem(inventory);
	itemSystem.spawnItem(inventory);
	itemSystem.spawnItem(inventory);
	itemSystem.spawnItem(inventory);

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
		for (auto& item : itemSystem.items()) {
			item->debugDraw(window);
		}
		window.display();
	}
}