#include "Button.h"


Button::Button() {
	font = sf::Font();
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating button." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Button", font, DEFAULT_FONT_SIZE);
	float text_x = text.getGlobalBounds().width / 2;
	float text_y = text.getGlobalBounds().height / 2;
	text.setPosition(text_x, text_y);

	rect = sf::RectangleShape(sf::Vector2f(130, 35));
	rect.setFillColor(sf::Color::Red);
}

Button::Button(std::string val) {
	Button();
	text.setString(val);
}

Button::~Button() {

}


void Button::show(sf::RenderWindow & window) {
	window.draw(rect);
	window.draw(text);
}


void Button::setText(std::string val) {
	text.setString(val);
}

void Button::setFontSize(uint16_t size) {
	text.setCharacterSize(size);
}

void Button::setTextColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void Button::setPosition(float x, float y) {
	rect.setPosition(x, y);

	float text_x = x + (rect.getSize().x - text.getGlobalBounds().width) / 2;
	float text_y = y + (rect.getSize().y - text.getGlobalBounds().height) / 2;
	text.setPosition(text_x, text_y);
}

void Button::setSize(float w, float h) {
	rect.setSize(sf::Vector2f(w, h));
}

void Button::setColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
	rect.setFillColor(sf::Color(r, g, b, a));
}


std::string Button::getText() {
	return text.getString();
}

ElementTypes Button::getElementType() {
	return ElementTypes::BUTTON;
}

float Button::getX() {
	return rect.getPosition().x;
}

float Button::getY() {
	return rect.getPosition().y;
}

float Button::getWidth() {
	return rect.getSize().x;
}

float Button::getHeight() {
	return rect.getSize().y;
}
