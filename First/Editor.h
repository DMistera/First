#pragma once
#include "State.h"
#include "SFML/System/Vector2.hpp"
#include "Block.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "MapObject.h"
#include <vector>
#include "Map.h"

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
private:
	unsigned int m_gridSize;
	Vector2i* m_mousePos;
	RectangleShape m_selectionHighlight;
	Map map;
	vector<MapObject> m_templates;
};

