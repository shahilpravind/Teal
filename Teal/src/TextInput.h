#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include "Constants.h"
#include "Drawable.h"
#include "ElementTypes.h"


class TextInput : public Drawable {
private:
	bool inputActive = false;
	sf::Font font;
	sf::RectangleShape rect;
	sf::Text text;

public:
	TextInput();
	~TextInput();

	void onClick(int, int) override;
	void onTextEntered(sf::Uint32) override;

	void show(sf::RenderWindow &) override;
	void addChar(sf::String);
	void backspace();
	void resetSize();

	void setActive();
	void setInActive();

	void setHint(std::string);
	void setText(std::string);
	void setFontSize(uint16_t);
	void setHintColor(uint32_t, uint32_t, uint32_t, uint32_t);
	void setColor(uint32_t, uint32_t, uint32_t, uint32_t);
	void setPosition(float, float) override;
	void setSize(float, float) override;

	std::string getText();
	bool getState();
	ElementTypes getElementType() override;
	float getX() override;
	float getY() override;
	float getWidth() override;
	float getHeight() override;
};
