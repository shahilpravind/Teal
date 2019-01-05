#include "TextInput.h"


TextInput::TextInput() {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}
	
	text = sf::Text("Hello", font, 22);
	
	rect = sf::RectangleShape(sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height));
	rect.setPosition(sf::Vector2f(text.getPosition().x, text.getPosition().y));
	rect.setFillColor(sf::Color::Red);
}

TextInput::TextInput(float x, float y) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Hello", font, 22);
	text.setPosition(x, y);

	rect = sf::RectangleShape(sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height));
	rect.setPosition(sf::Vector2f(text.getPosition().x, text.getPosition().y));
	rect.setFillColor(sf::Color::Red);
}

TextInput::~TextInput() {

}


void TextInput::show(sf::RenderWindow & window) {
	window.draw(rect);
	window.draw(text);
}

void TextInput::addChar(const sf::String & t) {
	sf::String str = sf::String();
	str += text.getString();
	str += t;
	text.setString(str);
}

void TextInput::backspace() {
	sf::String str = sf::String();
	str += text.getString();
	str.erase(str.getSize()-1, 1);
	text.setString(str);
}


void TextInput::setHint(const std::string & t) {
	text.setString(t);
	text.setStyle(sf::Text::Italic);
}

void TextInput::setText(const std::string & t) {
	text.setString(t);
}

void TextInput::setFontSize(const unsigned int & s) {
	text.setCharacterSize(s);
}

void TextInput::setHintColor(const int & r, const int & g, const int & b, const int & a = 255) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void TextInput::setColor(const int & r, const int & g, const int & b, const int & a = 255) {
	text.setFillColor(sf::Color(r, g, b, a));
}


std::string TextInput::getText() {
	return text.getString();
}

float TextInput::getX() {
	return text.getPosition().x;
}

float TextInput::getY() {
	return text.getPosition().y;
}

float TextInput::getWidth() {
	return text.getGlobalBounds().width;
}

float TextInput::getHeight() {
	return text.getGlobalBounds().height;
}
