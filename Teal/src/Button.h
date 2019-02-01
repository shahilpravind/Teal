#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include "Constants.h"
#include "Drawable.h"
#include "ElementTypes.h"


class Button : public Drawable {
private:
	sf::Font font;
	sf::RectangleShape rect;
	sf::Text text;

public:
	Button();
	Button(std::string);
	~Button();

	void show(sf::RenderWindow &) override;

	void setText(std::string);
	void setFontSize(uint16_t);
	void setTextColor(uint32_t, uint32_t, uint32_t, uint32_t);
	void setPosition(float, float) override;
	void setSize(float, float) override;
	void setColor(uint32_t, uint32_t, uint32_t, uint32_t);

	std::string getText();
	ElementTypes getElementType() override;
	float getX() override;
	float getY() override;
	float getWidth() override;
	float getHeight() override;
};
