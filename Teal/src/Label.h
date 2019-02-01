#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include "Constants.h"
#include "Drawable.h"


class Label : public Drawable {
private:
	float width = 0;
	float height = 0;

	sf::Text text;
	sf::Font font;

public:
	Label();
	Label(std::string);
	~Label();

	void show(sf::RenderWindow &) override;
	void resetSize();

	void setText(std::string);
	void setFontSize(uint16_t);
	void setColor(uint32_t, uint32_t, uint32_t, uint32_t);
	void setPosition(float, float) override;
	void setSize(float, float) override;

	std::string getString();
	ElementTypes getElementType() override;
	float getX() override;
	float getY() override;
	float getWidth() override;
	float getHeight() override;
};
