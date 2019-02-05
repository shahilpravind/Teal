#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Application.h"
#include "Constants.h"
#include "Drawable.h"
#include "Layout.h"


class VerticalLayout : public Layout {
private:
	Application* app;

public:
	VerticalLayout(Application*);
	~VerticalLayout();

	void add(Drawable &) override;
	void freeze() override;
};

