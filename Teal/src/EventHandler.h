#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Drawable.h"
#include "EventTypes.h"
#include "TextInput.h"


class EventHandler {
private:
	std::map < EventTypes, std::vector<Drawable*> >* events;
	sf::Event event;

public:
	EventHandler();
	~EventHandler();

	void update(sf::RenderWindow &);
	void registerEvent(EventTypes, Drawable*);
};

