#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Label
{
	private:
		sf::Text text;
		sf::Font font;

	public:
		Label();
		Label(const std::string &);
		Label(const float &, const float &);
		Label(const std::string &, const float &, const float &);
		~Label();

		void show(sf::RenderWindow &);

		void setText(const std::string &);
		void setFontSize(const unsigned int &);
		void setColor(const unsigned int &, const unsigned int &, const unsigned int &, const unsigned int &);
		void setX(const float &);
		void setY(const float &);
		void setPosition(const float &, const float &);

		std::string getString();
		float getX();
		float getY();
};
