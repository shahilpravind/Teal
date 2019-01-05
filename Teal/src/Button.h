#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Button {
	private:
		sf::RectangleShape rect;
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::Color color;

		sf::Font font;
		sf::Text text;

	public:
		Button(float x = 0, float y = 0, float w = 130, float h = 35);
		~Button();

		void show(sf::RenderWindow &);

		void setText(std::string);
		void setFontSize(const unsigned int &);
		void setTextColor(const int &, const int &, const int &, const int &);
		std::string getText();
		sf::Text getTextObj();

		/* Setters */

		void setX(float);
		void setY(float);
		void setPosition(float, float);

		void setWidth(float);
		void setHeight(float);
		void setSize(float, float);

		void setColor(int, int, int, int);

		/* Getters */

		float getX();
		float getY();
		float getWidth();
		float getHeight();

		sf::Color getColor();
};
