#include "Checkbox.h"


Checkbox::Checkbox() {
	font = sf::Font();
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	rect = sf::RectangleShape(sf::Vector2f(15, 15));
	rect.setPosition(OUTLINE_THICKNESS, DEFAULT_PADDING + OUTLINE_THICKNESS);
	rect.setOutlineColor(sf::Color(255, 0, 0, 255));
	rect.setOutlineThickness(OUTLINE_THICKNESS);
	rect.setFillColor(sf::Color(255, 0, 0, 0));

	text = sf::Text("Checkbox", font, DEFAULT_FONT_SIZE);
}

Checkbox::Checkbox(std::string val) {
	Checkbox();
	text.setString(val);
}

Checkbox::~Checkbox() {

}


void Checkbox::show(sf::RenderWindow &window) {
	window.draw(rect);
	window.draw(text);
}

void Checkbox::setChecked(bool state) {
	if (state) {
		rect.setFillColor(sf::Color(rect.getFillColor().r, rect.getFillColor().g, rect.getFillColor().b, 255));
	} else {
		rect.setFillColor(sf::Color(rect.getFillColor().r, rect.getFillColor().g, rect.getFillColor().b, 0));
	}
}

bool Checkbox::isChecked() {
	return (rect.getFillColor().a == 0 ? true : false);
}


void Checkbox::setText(std::string val) {
	text.setString(val);
}

void Checkbox::setFontSize(uint16_t size) {
	text.setCharacterSize(size);
}

void Checkbox::setTextColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void Checkbox::setMarkerColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	rect.setFillColor(sf::Color(r, g, b, a));
	rect.setOutlineColor(sf::Color(r, g, b, a));
}

void Checkbox::setPosition(float x, float y) {
	this->x = x;
	this->y = y;

	rect.setPosition(DEFAULT_PADDING + OUTLINE_THICKNESS + x, y + DEFAULT_PADDING + OUTLINE_THICKNESS);
	text.setPosition(rect.getPosition().x + rect.getSize().x + DEFAULT_PADDING * 2, y);
}

void Checkbox::setSize(float width, float height) {
	this->width = width;
	this->height = height;
}


ElementTypes Checkbox::getElementType() {
	return ElementTypes::CHECKBOX;
}

float Checkbox::getX() {
	return x;
}

float Checkbox::getY() {
	return y;
}

float Checkbox::getWidth() {
	return width;
}

float Checkbox::getHeight() {
	return height;
}

