#include "EditorMap.h"



EditorMap::EditorMap() {
}


EditorMap::~EditorMap() {
}

bool EditorMap::init(Vector2i* mousePos, Map& map) {
	m_mousePos = mousePos;
	m_map = &map;
	m_gridSize = 32;
	return true;
	m_selectionHighlight.setSize(Vector2f((float)m_gridSize, (float)m_gridSize));
}

bool EditorMap::update(int deltaTime, MapObject* selectedTemplate) {
	//Highlight
	float x = (float)(m_mousePos->x - m_mousePos->x % m_gridSize);
	float y = (float)(m_mousePos->y - m_mousePos->y % m_gridSize);
	m_selectionHighlight.setPosition(Vector2f(x, y));

	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (selectedTemplate != nullptr) {
			m_map->addObject((MapObject*)selectedTemplate->copy());
		}
	}
	return true;
}

void EditorMap::draw(RenderTarget& target, RenderStates states) const {
	target.draw(*m_map);
	target.draw(m_selectionHighlight);
}

Vector2i EditorMap::getBlock(Vector2i point) {
	int x = point.x / m_gridSize;
	int y = point.y / m_gridSize;
	return Vector2i(x, y);
}

