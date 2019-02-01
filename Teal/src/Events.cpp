#include "Events.h"


Events::Events() {
	event = sf::Event();
	onClicks = new std::map<Drawable *, void(*)()>();
	textInputs = new std::vector<TextInput*>();
}


Events::~Events() {
	delete onClicks;
	delete textInputs;
}


void Events::update(sf::RenderWindow &window) {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				for (auto const& item : *onClicks) {
					if (event.mouseButton.x >= item.first->getX() && event.mouseButton.x <= item.first->getX() + item.first->getWidth() && event.mouseButton.y >= item.first->getY() && event.mouseButton.y <= item.first->getY() + item.first->getHeight()) {
						(item.second)();
					}
				}

				for (TextInput* ti : *textInputs) {
					if (event.mouseButton.x >= ti->getX() && event.mouseButton.x <= ti->getX() + ti->getWidth() && event.mouseButton.y >= ti->getY() && event.mouseButton.y <= ti->getY() + ti->getHeight()) {
						ti->setActive();
					} else {
						ti->setInActive();
					}
				}
			}
		}

		if (event.type == sf::Event::TextEntered) {
			for (TextInput* ti : *textInputs) {
				if (ti->getState()) {
					if (event.text.unicode == 8) {
						ti->backspace();
					} else {
						ti->addChar(event.text.unicode);
					}
				}
			}
		}
	}
}


void Events::addOnClick(Drawable &d, void(*fp)()) {
	onClicks->insert(std::pair<Drawable*, void(*)()>(&d, fp));
}

void Events::addTextInput(TextInput &t) {
	textInputs->push_back(&t);
}
