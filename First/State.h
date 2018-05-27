#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Drawable.hpp"

using namespace sf;

class State : public Drawable {
public:
	State();
	~State();
	virtual bool init() = 0;
	virtual bool update(int deltaTime) = 0;
};

