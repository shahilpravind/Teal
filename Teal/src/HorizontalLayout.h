#pragma once

#include "Application.h"
#include "Constants.h"
#include "Layout.h"


class HorizontalLayout : public Layout {
private:
	Application* app;

public:
	HorizontalLayout(Application*);
	~HorizontalLayout();

	void add(Drawable &) override;
	void freeze() override;
};

