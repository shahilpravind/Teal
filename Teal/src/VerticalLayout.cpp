#include "VerticalLayout.h"


VerticalLayout::VerticalLayout(Application* app) {
	this->app = app;
	drawables = new std::vector<Drawable*>();

	this->x = 0;
	this->y = 0;
	this->width = WINDOW_WIDTH;
	this->height = WINDOW_HEIGHT;
}

VerticalLayout::~VerticalLayout() {
	delete drawables;
}


void VerticalLayout::add(Drawable &d) {
	Layout::add(d);

	if (app != nullptr && d.getElementType() == ElementTypes::TEXT_INPUT) {
		app->getEventHandler()->registerEvent(EventTypes::OnClick, &d);
		app->getEventHandler()->registerEvent(EventTypes::TextEntered, &d);
	}
}

void VerticalLayout::freeze() {
	float h = this->height / drawables->size();

	for (uint32_t i = 0; i < drawables->size(); i++) {
		(*drawables)[i]->setSize(this->width, h);
		(*drawables)[i]->setPosition(0, i*h);
	}
}

