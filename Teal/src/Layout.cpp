#include "Layout.h"


Layout::Layout() {

}


Layout::~Layout() {

}


void Layout::add(Drawable &d) {
	drawables->push_back(&d);
}

void Layout::draw(sf::RenderWindow &window) {
	for (Drawable* drawable : *drawables) {
		drawable->show(window);
	}
}


void Layout::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

void Layout::setSize(float w, float h) {
	this->width = w;
	this->height = h;
}


float Layout::getX() {
	return this->x;
}

float Layout::getY() {
	return this->y;
}

float Layout::getWidth() {
	return this->width;
}

float Layout::getHeight() {
	return this->height;
}

