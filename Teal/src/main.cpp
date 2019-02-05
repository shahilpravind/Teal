#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Button.h"
#include "Checkbox.h"
#include "Constants.h"
#include "EventTypes.h"
#include "GridLayout.h"
#include "HorizontalLayout.h"
#include "Label.h"
#include "TextInput.h"
#include "VerticalLayout.h"


void buttonClick() {
	std::cout << "Hello from the button" << std::endl;
}


int main() {
	Application* app = new Application();

	Button button = Button();
	button.setPosition(200, 30);
	app->bind(button, EventTypes::OnClick, buttonClick);

	Label label = Label();
	label.setPosition(300, 300);

	TextInput textInput = TextInput();
	textInput.setPosition(400, 400);

	Checkbox checkbox = Checkbox();
	checkbox.setChecked(false);

	GridLayout layout = GridLayout(app);
	layout.add(button);
	layout.add(label);
	layout.add(textInput);
	layout.add(checkbox);
	layout.freeze();

	app->add(layout);
	app->run();


	// ----- Cleanup -----
	delete app;

	return 0;
}
