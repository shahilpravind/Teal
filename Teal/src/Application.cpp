#include "Application.h"


Application::Application() {
	drawables = new std::vector<Drawable*>;
	layouts = new std::vector<Layout*>;
	eventHandler = new EventHandler();
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
}

Application::Application(uint32_t width, uint32_t height) {
	Application();
	window.setSize(sf::Vector2u(width, height));
}

Application::Application(uint32_t width, uint32_t height, std::string title) {
	Application();
	window.setSize(sf::Vector2u(width, height));
	window.setTitle(title);
}

Application::~Application() {
	delete drawables;
	delete layouts;
	delete eventHandler;
}


void Application::draw() {
	for (Drawable* drawable : *drawables) {
		drawable->show(window);
	}

	for (Layout* layout : *layouts) {
		layout->draw(window);
	}
}


void Application::run() {
	while (window.isOpen()) {
		eventHandler->update(window);

		window.clear();
		this->draw();
		window.display();
	}
}

void Application::add(Drawable &drawable) {
	Drawable *temp = &drawable;
	drawables->push_back(temp);

	if (drawable.getElementType() == ElementTypes::TEXT_INPUT) {
		eventHandler->registerEvent(EventTypes::OnClick, &drawable);
		eventHandler->registerEvent(EventTypes::TextEntered, &drawable);
	}
}

void Application::add(Layout &layout) {
	layouts->push_back(&layout);
}

void Application::bind(Drawable &d, EventTypes et, void(*fp)()) {
	if (et == EventTypes::OnClick) {
		d.bind(fp);
		eventHandler->registerEvent(et, &d);
	}
}


void Application::setTitle(std::string title) {
	window.setTitle(title);
}

void Application::setPosition(uint32_t x, uint32_t y) {
	window.setPosition(sf::Vector2i(x, y));
}

void Application::setSize(uint32_t w, uint32_t h) {
	window.setSize(sf::Vector2u(w, h));
}


EventHandler* Application::getEventHandler() {
	return eventHandler;
}

uint32_t Application::getX() {
	return window.getPosition().x;
}

uint32_t Application::getY() {
	return window.getPosition().y;
}

uint32_t Application::getWidth() {
	return window.getSize().x;
}

uint32_t Application::getHeight() {
	return window.getSize().y;
}
