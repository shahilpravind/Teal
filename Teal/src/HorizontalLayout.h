#pragma once

#include "Constants.h"
#include "Layout.h"


class HorizontalLayout : public Layout {
public:
	HorizontalLayout();
	~HorizontalLayout();

	void freeze() override;
};

