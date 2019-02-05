#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Drawable.h"
#include "ElementTypes.h"


class Checkbox : public Drawable {
private:
	const float OUTLINE_THICKNESS = 3;
	float x = 0, y = 0;
	float width = 0, height = 0;

	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;

public:
	Checkbox();
	Checkbox(std::string);
	~Checkbox();

	void onClick(int, int) override;

	void show(sf::RenderWindow &);
	void setChecked(bool);
	bool isChecked();

	void setText(std::string);
	void setFontSize(uint16_t);
	void setTextColor(uint8_t, uint8_t, uint8_t, uint8_t);
	void setMarkerColor(uint8_t, uint8_t, uint8_t, uint8_t);
	void setPosition(float, float);
	void setSize(float, float);

	ElementTypes getElementType();
	float getX();
	float getY();
	float getWidth();
	float getHeight();
};

