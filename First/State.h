#pragma once

#include "SFML/Graphics.hpp"

class State
{
public:
	State();
	~State();
	virtual bool init() = 0;
	virtual bool update() = 0;
	virtual bool draw(sf::RenderWindow* window) = 0;
};

