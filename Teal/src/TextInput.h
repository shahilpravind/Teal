#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class TextInput
{
	private:
		sf::RectangleShape rect;
		sf::Text text;
		sf::Font font;

	public:
		TextInput();
		TextInput(float, float);
		~TextInput();

		void show(sf::RenderWindow &);
		void backspace();
		void addChar(const sf::String &);

		void setHint(const std::string &);
		void setText(const std::string &);
		void setFontSize(const unsigned int &);
		void setHintColor(const int &, const int &, const int &, const int &);
		void setColor(const int &, const int &, const int &, const int &);

		std::string getText();
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		sf::Text getObj();
};
