#pragma once
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "Map.h"
#include "State.h"
class Gameplay : public State
{
public:
	Gameplay();
	~Gameplay();
	void update();
	void init();
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	Map m_map;
};

