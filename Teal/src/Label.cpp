#include "Label.h"


Label::Label() {
	font = sf::Font();
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Label", font, DEFAULT_FONT_SIZE);
}

Label::Label(std::string val) {
	Label();
	text.setString(val);
}

Label::~Label() {

}


void Label::show(sf::RenderWindow & window) {
	window.draw(text);
}

void Label::resetSize() {
	width = 0;
	height = 0;
}


void Label::setText(std::string val) {
	text.setString(val);

}

void Label::setFontSize(uint16_t size) {
	text.setCharacterSize(size);
}

void Label::setColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void Label::setPosition(float x, float y) {
	text.setPosition(x, y);
}

void Label::setSize(float w, float h) {
	width = w;
	height = h;
}


std::string Label::getString() {
	return text.getString();
}

ElementTypes Label::getElementType() {
	return ElementTypes::LABEL;
}

float Label::getX() {
	return text.getPosition().x;
}

float Label::getY() {
	return text.getPosition().y;
}

float Label::getWidth() {
	return text.getGlobalBounds().width;
}

float Label::getHeight() {
	return text.getGlobalBounds().height;
}
