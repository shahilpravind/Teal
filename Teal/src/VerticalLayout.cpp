#include "VerticalLayout.h"


VerticalLayout::VerticalLayout() {
	drawables = new std::vector<Drawable*>();

	this->x = 0;
	this->y = 0;
	this->width = WINDOW_WIDTH;
	this->height = WINDOW_HEIGHT;
}

VerticalLayout::~VerticalLayout() {
	delete drawables;
}


void VerticalLayout::freeze() {
	float h = this->height / drawables->size();

	for (uint32_t i = 0; i < drawables->size(); i++) {
		(*drawables)[i]->setSize(this->width, h);
		(*drawables)[i]->setPosition(0, i*h);
	}
}

