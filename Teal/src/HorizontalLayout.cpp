#include "HorizontalLayout.h"


HorizontalLayout::HorizontalLayout(Application* app) {
	this->app = app;
	drawables = new std::vector<Drawable*>();

	this->x = 0;
	this->y = 0;
	this->width = WINDOW_WIDTH;
	this->height = WINDOW_HEIGHT;
}

HorizontalLayout::~HorizontalLayout() {
	delete drawables;
}


void HorizontalLayout::add(Drawable &d) {
	Layout::add(d);

	if (app != nullptr && d.getElementType() == ElementTypes::TEXT_INPUT) {
		app->getEventHandler()->registerEvent(EventTypes::OnClick, &d);
		app->getEventHandler()->registerEvent(EventTypes::TextEntered, &d);
	}
}

void HorizontalLayout::freeze() {
	float w = this->width / drawables->size();

	for (uint32_t i = 0; i < drawables->size(); i++) {
		(*drawables)[i]->setSize(w, this->height);
		(*drawables)[i]->setPosition(i*w, 0);
	}
}
