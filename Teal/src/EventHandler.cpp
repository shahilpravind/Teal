#include "EventHandler.h"


EventHandler::EventHandler() {
	event = sf::Event();
	events = new std::map < EventTypes, std::vector<Drawable*> >();
}


EventHandler::~EventHandler() {
	delete events;
}


void EventHandler::update(sf::RenderWindow &window) {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (events->find(EventTypes::OnClick) != events->end()) {
					for (Drawable* d : (*events)[EventTypes::OnClick]) {
						d->onClick(event.mouseButton.x, event.mouseButton.y);
					}
				}
			}
		}

		if (event.type == sf::Event::TextEntered) {
			if (events->find(EventTypes::TextEntered) != events->end()) {
				for (Drawable* d : (*events)[EventTypes::TextEntered]) {
					d->onTextEntered(event.text.unicode);
				}
			}
		}
	}
}


void EventHandler::registerEvent(EventTypes et, Drawable *d) {
	(*events)[et].push_back(d);
}
