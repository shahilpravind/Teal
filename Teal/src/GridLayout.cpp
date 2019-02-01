#include "GridLayout.h"


GridLayout::GridLayout() {
	drawables = new std::vector<Drawable*>();

	this->x = 0;
	this->y = 0;
	this->width = WINDOW_WIDTH;
	this->height = WINDOW_HEIGHT;
}

GridLayout::~GridLayout() {
	delete drawables;
}


void GridLayout::freeze() {
	float w = this->width / cols;
	float h = this->height / rows;

	for (uint32_t i = 0, j = 0; i < drawables->size(); i++) {
		(*drawables)[i]->setSize(w, h);
		(*drawables)[i]->setPosition(i % cols * w, j * h);

		if (i == cols - 1)
			j++;
	}
}


void GridLayout::setCols(uint16_t n) {
	cols = n;
}

void GridLayout::setRows(uint16_t n) {
	rows = n;
}


uint16_t GridLayout::getCols() {
	return cols;
}

uint16_t GridLayout::getRows() {
	return rows;
}
