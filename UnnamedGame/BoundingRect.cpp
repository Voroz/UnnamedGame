#include "BoundingRect.h"



BoundingRect::BoundingRect(){
	_position = sf::Vector2f(0, 0);
	_center = sf::Vector2f(0, 0);
	_width = 0;
	_height = 0;
	_debugColor = sf::Color::Red;
}
BoundingRect::~BoundingRect(){

}

sf::Vector2f BoundingRect::pos() {
	return _position;
}
sf::Vector2f BoundingRect::center() {
	return _center;
}
float BoundingRect::top() {
	return -_center.y;
}
float BoundingRect::left() {
	return -_center.x;
}
float BoundingRect::bottom() {
	return top() + _height;
}
float BoundingRect::right() {
	return left() + _width;
}
sf::Vector2f BoundingRect::topLeft() {
	return sf::Vector2f(left(), top());
}
sf::Vector2f BoundingRect::topRight() {
	return sf::Vector2f(right(), top());
}
sf::Vector2f BoundingRect::bottomRight() {
	return sf::Vector2f(right(), bottom());
}
sf::Vector2f BoundingRect::bottomLeft() {
	return sf::Vector2f(left(), bottom());
}
float BoundingRect::width() {
	return _width;
}
float BoundingRect::height() {
	return _height;
}

void BoundingRect::setPos(const sf::Vector2f pos) {
	_position = pos;
}
void BoundingRect::setPos(const float x, const float y) {
	_position = sf::Vector2f(x, y);
}
void BoundingRect::setCenter(const sf::Vector2f center) {
	_center = center;
}
void BoundingRect::setCenter(const float x, const float y) {
	_center = sf::Vector2f(x, y);
}
void BoundingRect::setWidth(const float width) {
	_width = width;
}
void BoundingRect::setHeight(const float height) {
	_height = height;
}

bool BoundingRect::intersects(BoundingRect rect) {
	float aLeft = pos().x + left();
	float aRight = pos().x + right();
	float aTop = pos().y + top();
	float aBot = pos().y + bottom();

	float bLeft = rect.pos().x + rect.left();
	float bRight = rect.pos().x + rect.right();
	float bTop = rect.pos().y + rect.top();
	float bBot = rect.pos().y + rect.bottom();

	return (aRight > bLeft && aLeft < bRight &&
		aBot > bTop && aTop < bBot);
}
bool BoundingRect::contains(sf::Vector2f point) {
	float aLeft = pos().x + left();
	float aRight = pos().x + right();
	float aTop = pos().y + top();
	float aBot = pos().y + bottom();

	return (point.x > aLeft && point.x < aRight &&
		point.y > aTop && point.y < aBot);
}

void BoundingRect::debugDraw(sf::RenderWindow &window) {
	_debugShape.setSize(sf::Vector2f(width(), height()));
	_debugShape.setOutlineColor(_debugColor);
	_debugShape.setOutlineThickness(1);
	_debugShape.setFillColor(sf::Color::Transparent);
	_debugShape.setPosition(pos());
	window.draw(_debugShape);
}