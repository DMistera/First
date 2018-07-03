#pragma once
#include "State.h"
#include "Map.h"
class EditorMap : public State {
public:
	EditorMap();
	~EditorMap();
	bool init(Vector2i* mousePos, Map& map);
	bool update(int deltaTime, MapObject* selectedTemplate);
	Map* getMap();
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	Vector2i getBlock(Vector2i point);
private:
	unsigned int m_gridSize;
	Map * m_map;
	Vector2i* m_mousePos;
	RectangleShape m_selectionHighlight;
};

