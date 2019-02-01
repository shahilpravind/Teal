#pragma once

#include <SFML/Graphics.hpp>
#include "ElementTypes.h"

class Drawable {
public:
	Drawable();
	~Drawable();

	virtual void show(sf::RenderWindow &) = 0;

	virtual void setPosition(float, float) = 0;
	virtual void setSize(float, float) = 0;

	virtual ElementTypes getElementType() = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual float getWidth() = 0;
	virtual float getHeight() = 0;
};

