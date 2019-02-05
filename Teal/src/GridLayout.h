#pragma once

#include <cstdint>
#include "Application.h"
#include "Constants.h"
#include "Layout.h"


class GridLayout : public Layout {
private:
	Application* app;
	uint16_t cols = 4;
	uint16_t rows = 4;

public:
	GridLayout(Application*);
	~GridLayout();

	void add(Drawable &) override;
	void freeze() override;

	void setCols(uint16_t);
	void setRows(uint16_t);

	uint16_t getCols();
	uint16_t getRows();
};

