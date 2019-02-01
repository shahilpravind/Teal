#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"
#include "Drawable.h"
#include "Layout.h"


class VerticalLayout : public Layout {
public:
	VerticalLayout();
	~VerticalLayout();

	void freeze() override;
};

