#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Constants.h"
#include "Label.h"
#include "TextInput.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	sf::Event event;

	Button button = Button(200, 100);
	Label label = Label(300, 300);

	TextInput textInput = TextInput(400, 400);
	bool textInputActive = false;
	
	while (window.isOpen()) {
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (event.mouseButton.x >= button.getX() && event.mouseButton.x <= button.getX() + button.getWidth() && event.mouseButton.y >= button.getY() && event.mouseButton.y <= button.getY() + button.getHeight()) {
						// button clicked
						std::cout << "Button clicked" << std::endl;
					}

					if (event.mouseButton.x >= textInput.getX() && event.mouseButton.x <= textInput.getX() + textInput.getWidth() && event.mouseButton.y >= textInput.getY() && event.mouseButton.y <= textInput.getY() + textInput.getHeight()) {
						textInputActive = true;
						std::cout << textInputActive << std::endl;
					}
					else {
						textInputActive = false;
						std::cout << textInputActive << std::endl;
					}
				}
			}

			if (textInputActive && event.type == sf::Event::TextEntered) {
				if (event.text.unicode == 8) {
					textInput.backspace();
				} else {
					textInput.addChar(event.text.unicode);
				}
			}
		}

		window.clear();
		label.show(window);
		button.show(window);
		textInput.show(window);
		window.display();
	}

	return 0;
}
