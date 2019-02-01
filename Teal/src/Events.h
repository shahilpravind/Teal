#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Drawable.h"
#include "EventTypes.h"
#include "TextInput.h"


class Events {
private:
	std::map<Drawable*, void(*)()>* onClicks;
	std::vector<TextInput*>* textInputs;

	sf::Event event;

public:
	Events();
	~Events();

	void update(sf::RenderWindow &);
	void addOnClick(Drawable &, void(*)());
	void addTextInput(TextInput &);
};

