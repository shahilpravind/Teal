#include "Label.h"


Label::Label() {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Label", font, 22);
}

Label::Label(const std::string & t) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text(t, font, 22);
}

Label::Label(const float & x, const float & y) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Label", font, 22);
	text.setPosition(x, y);
}

Label::Label(const std::string & t, const float & x, const float & y) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text(t, font, 22);
	text.setPosition(x, y);
}

Label::~Label() {

}


void Label::show(sf::RenderWindow & window) {
	window.draw(text);
}


void Label::setText(const std::string & t) {
	text.setString(t);

}

void Label::setFontSize(const unsigned int & s) {
	text.setCharacterSize(s);
}

void Label::setColor(const unsigned int & r, const unsigned int & g, const unsigned int & b, const unsigned int & a = 255) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void Label::setX(const float & x) {
	text.setPosition(x, text.getPosition().y);
}

void Label::setY(const float & y) {
	text.setPosition(text.getPosition().x, y);
}

void Label::setPosition(const float & x, const float & y) {
	text.setPosition(x, y);
}


std::string Label::getString() {
	return text.getString();
}

float Label::getX() {
	return text.getPosition().x;
}

float Label::getY() {
	return text.getPosition().y;
}
