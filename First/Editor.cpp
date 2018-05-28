#include "Editor.h"




Editor::Editor(Vector2i* mousePos) {
	m_mousePos = mousePos;
}

Editor::~Editor() {
}

bool Editor::init() {
	m_gridSize = 32;
	m_layoutWidth = 20;
	m_iconSize = 64;
	m_selectionHighlight.setSize(Vector2f((float)m_gridSize, (float)m_gridSize));

	m_templateLayout.setSize(Vector2f((float)(m_iconSize + 2*m_layoutWidth), 600.0f));
	m_templateLayout.setFillColor(Color(255, 255, 255, 128));

	//Templates
	m_templates.push_back(new Block());
	
	float y = (float)m_layoutWidth;
	for (MapObject* mapObject : m_templates) {
		mapObject->init();
		mapObject->getFrame().setPosition(Vector2f((float)m_layoutWidth, y));
		//Normalise
		mapObject->getFrame().setScale(Vector2f(m_iconSize/mapObject->getFrame().getWidth(), m_iconSize/mapObject->getFrame().getHeight()));
		y += m_iconSize;
	}

	return true;
}

bool Editor::update(int deltaTime) {
	//Highlight
	float x = (float)(m_mousePos->x - m_mousePos->x % m_gridSize);
	float y = (float)(m_mousePos->y - m_mousePos->y % m_gridSize);
	m_selectionHighlight.setPosition(Vector2f(x, y));

	if (Mouse::isButtonPressed(Mouse::Left)) {
		//TODO Copy instance of a class
		m_selectedTemplate = getTemplateFromCursor();
	}
	if (m_selectedTemplate != nullptr) {
		m_selectedTemplate->getFrame().setPosition((Vector2f)*m_mousePos);
	}

	return true;
}

void Editor::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_templateLayout);
	for (MapObject* mapObject : m_templates) {
		target.draw(*mapObject);
	}
	target.draw(m_selectionHighlight);
}

Vector2i Editor::getBlock(Vector2i point)
{
	int x = point.x / m_gridSize;
	int y = point.y / m_gridSize;
	return Vector2i(x, y);
}

MapObject * Editor::getTemplateFromCursor()
{
	for (MapObject* mapObject : m_templates) {
		if (mapObject->getFrame().contains((Vector2f)*m_mousePos)) {
			return mapObject;
		}
	}
	return nullptr;
}
