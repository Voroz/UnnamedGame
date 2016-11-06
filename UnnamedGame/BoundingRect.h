#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System/Vector2.hpp"

class BoundingRect
{
public:
	BoundingRect();
	~BoundingRect();

	sf::Vector2f pos();
	sf::Vector2f center();
	float top();
	float left();
	float bottom();
	float right();
	float width();
	float height();
	sf::Vector2f topLeft();
	sf::Vector2f topRight();
	sf::Vector2f bottomRight();
	sf::Vector2f bottomLeft();

	void setPos(const sf::Vector2f pos);
	void setPos(const float x, const float y);
	void setCenter(const sf::Vector2f center);
	void setCenter(const float x, const float y);
	void setWidth(const float width);
	void setHeight(const float height);

	bool intersects(BoundingRect rect);
	bool contains(sf::Vector2f point);

	virtual void debugDraw(sf::RenderWindow &window);

protected:
	sf::Vector2f _position;
	sf::Vector2f _center;
	float _width;
	float _height;
	sf::RectangleShape _debugShape;
	sf::Color _debugColor;
};

