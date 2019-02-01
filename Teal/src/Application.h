#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdint>
#include "Constants.h"
#include "Drawable.h"
#include "ElementTypes.h"
#include "Events.h"
#include "EventTypes.h"
#include "Layout.h"
#include "TextInput.h"


class Application {
private:
	std::vector<Drawable*>* drawables;
	std::vector<Layout*>* layouts;
	Events* events;
	sf::RenderWindow window;

	void draw();

public:
	Application();
	Application(uint32_t, uint32_t);
	Application(uint32_t, uint32_t, std::string title);
	~Application();

	void run();
	void add(Drawable &);
	void add(Layout &);
	void bind(Drawable &, EventTypes, void(*)());

	void setTitle(std::string);
	void setPosition(uint32_t, uint32_t);
	void setSize(uint32_t, uint32_t);

	uint32_t getX();
	uint32_t getY();
	uint32_t getWidth();
	uint32_t getHeight();
};

