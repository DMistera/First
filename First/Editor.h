#pragma once
#include "State.h"
#include "SFML/System/Vector2.hpp"
#include "Block.h"

using namespace sf;

class Editor :
	public State {
public:
	Editor(Vector2i* mousePos);
	~Editor();

	virtual bool init() override;


	virtual bool update(int deltaTime) override;

protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	Block m_block;
};

