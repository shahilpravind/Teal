#pragma once

#include <vector>
#include "Drawable.h"


class Layout {
protected:
	std::vector<Drawable*>* drawables;
	float x, y, width, height;

public:
	Layout();
	~Layout();

	virtual void freeze() = 0;
	
	virtual void add(Drawable &);
	void draw(sf::RenderWindow &);

	void setPosition(float, float);
	void setSize(float, float);

	float getX();
	float getY();
	float getWidth();
	float getHeight();
};

