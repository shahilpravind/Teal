#include "TextInput.h"


TextInput::TextInput() {
	font = sf::Font();
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error: Unable to open font when creating label." << std::endl;
		system("Pause");
		exit(1);
	}

	text = sf::Text("Enter text", font, DEFAULT_FONT_SIZE);

	float rw = text.getGlobalBounds().width + DEFAULT_PADDING * 3;
	float rh = text.getGlobalBounds().height * 2 - DEFAULT_PADDING;
	rect = sf::RectangleShape(sf::Vector2f(rw, rh));
	rect.setFillColor(sf::Color::Red);

	text.setPosition(DEFAULT_PADDING, 0);
}

TextInput::~TextInput() {

}


void TextInput::onClick(int mx, int my) {
	if (mx >= this->getX() && mx <= this->getX() + this->getWidth() && my >= this->getY() && my <= this->getY() + this->getHeight()) {
		inputActive = true;
	} else if (inputActive) {
		inputActive = false;
	}
}

void TextInput::onTextEntered(sf::Uint32 code) {
	if (inputActive) {
		if (code == 8) {
			this->backspace();
		} else {
			this->addChar(code);
		}
	}
}


void TextInput::show(sf::RenderWindow & window) {
	window.draw(rect);
	window.draw(text);
}

void TextInput::addChar(sf::String val) {
	sf::String str = sf::String();
	str += text.getString();
	str += val;
	text.setString(str);
}

void TextInput::backspace() {
	if (text.getString().getSize() > 0) {
		sf::String str = sf::String();
		str += text.getString();
		str.erase(str.getSize() - 1, 1);
		text.setString(str);
	}
}

void TextInput::resetSize() {
	float rw = text.getGlobalBounds().width + DEFAULT_PADDING * 3;
	float rh = text.getGlobalBounds().height * 2 - DEFAULT_PADDING;
	rect.setSize(sf::Vector2f(rw, rh));
}


void TextInput::setActive() {
	inputActive = true;
}

void TextInput::setInActive() {
	inputActive = false;
}


void TextInput::setHint(std::string t) {
	text.setString(t);
	text.setStyle(sf::Text::Italic);
}

void TextInput::setText(std::string t) {
	text.setString(t);
}

void TextInput::setFontSize(uint16_t size) {
	text.setCharacterSize(size);
}

void TextInput::setHintColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void TextInput::setColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a) {
	text.setFillColor(sf::Color(r, g, b, a));
}

void TextInput::setPosition(float x, float y) {
	rect.setPosition(x, y);
	text.setPosition(x + DEFAULT_PADDING, y);
}

void TextInput::setSize(float w, float h) {
	rect.setSize(sf::Vector2f(w, h));
}


std::string TextInput::getText() {
	return text.getString();
}

bool TextInput::getState() {
	return inputActive;
}

ElementTypes TextInput::getElementType() {
	return ElementTypes::TEXT_INPUT;
}

float TextInput::getX() {
	return rect.getPosition().x;
}

float TextInput::getY() {
	return rect.getPosition().y;
}

float TextInput::getWidth() {
	return rect.getGlobalBounds().width;
}

float TextInput::getHeight() {
	return rect.getGlobalBounds().height;
}
