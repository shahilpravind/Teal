#include "Button.h"


Button::Button(float x, float y, float w, float h) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating button." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Button", font);
	text.setCharacterSize(22);
	float text_x = x + (w - text.getLocalBounds().width) / 2;
	float text_y = y + ( h/2 - text.getLocalBounds().height * 7/8 );
	text.setPosition(text_x, text_y);

	pos = sf::Vector2f(x, y);
	size = sf::Vector2f(w, h);
	color = sf::Color::Red;

	rect = sf::RectangleShape(size);
	rect.setPosition(pos);
	rect.setFillColor(color);
}

Button::~Button() {

}


void Button::show(sf::RenderWindow & window) {
	window.draw(rect);
	window.draw(text);
}


void Button::setText(std::string t) {
	text.setString(t);
}

void Button::setFontSize(const unsigned int & s) {
	text.setCharacterSize(s);
}

void Button::setTextColor(const int & r, const int & g, const int & b, const int & a = 255) {
	text.setFillColor(sf::Color(r, g, b, a));
}

std::string Button::getText() {
	return text.getString();
}

sf::Text Button::getTextObj() {
	return text;
}


/* Setters */

void Button::setX(float x) {
	pos.x = x;
	rect.setPosition(pos);
}

void Button::setY(float y) {
	pos.y = y;
	rect.setPosition(pos);
}

void Button::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;
	rect.setPosition(pos);
}

void Button::setWidth(float w) {
	size.x = w;
	rect.setSize(size);
}

void Button::setHeight(float h) {
	size.y = h;
	rect.setSize(size);
}

void Button::setSize(float w, float h) {
	size.x = w;
	size.y = h;
	rect.setSize(size);
}

void Button::setColor(int r, int g, int b, int a=255) {
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	rect.setFillColor(color);
}


/* Getters */

float Button::getX() {
	return pos.x;
}

float Button::getY() {
	return pos.y;
}

float Button::getWidth() {
	return size.x;
}

float Button::getHeight() {
	return size.y;
}

sf::Color Button::getColor() {
	return color;
}
