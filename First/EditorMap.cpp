#include "EditorMap.h"
#include <iostream>



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

	Vector2f mousePos = State::convertFromCursor(*m_mousePos);

	//Highlight
	float x = (float)(mousePos.x - (int)mousePos.x % m_gridSize);
	float y = (float)(mousePos.y - (int)mousePos.y % m_gridSize);
	m_selectionHighlight.setPosition(Vector2f(x, y));

	//Insert
	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (selectedTemplate != nullptr) {
			bool add = true;
			for (MapObject* mapObject : m_map->getMapObjects()) {
				if (mapObject->getFrame().getPosition() == Vector2f(x, y)) {
					add = false;
				}
			}
			if (add) {
				MapObject* o = (MapObject*)selectedTemplate->copy();
				o->getFrame().setPosition(Vector2f(x, y));
				m_map->addObject(o);
			}
		}
	}

	//Delete
	if (Mouse::isButtonPressed(Mouse::Right)) {
		for (MapObject* mapObject : m_map->getMapObjects()) {
			//Could be better
			bool x = mapObject->getFrame().getPosition().x <= m_mousePos->x && m_mousePos->x <= mapObject->getFrame().getPosition().x + mapObject->getFrame().getWidth();
			bool y = mapObject->getFrame().getPosition().y <= m_mousePos->y && m_mousePos->y <= mapObject->getFrame().getPosition().y + mapObject->getFrame().getHeight();
			if (x && y) {
				m_map->remove(mapObject);
				delete mapObject;
			}
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		m_view.move(Vector2f(1.0f*(float)deltaTime, 0.0f));
		cout << "D" << endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		m_view.move(Vector2f(-1.0f*(float)deltaTime, 0.0f));
		cout << "A" << endl;
	}

	return true;
}

void EditorMap::draw(RenderTarget& target, RenderStates states) const {
	State::draw(target, states);
	target.draw(*m_map);
	target.draw(m_selectionHighlight);
}

Vector2i EditorMap::getBlock(Vector2i point) {
	int x = point.x / m_gridSize;
	int y = point.y / m_gridSize;
	return Vector2i(x, y);
}

