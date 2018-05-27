#include "Editor.h"




Editor::Editor(Vector2i* mousePos) {
	m_mousePos = mousePos;
}

Editor::~Editor() {
}

bool Editor::init() {
	m_block.init();
	m_gridSize = 32;
	m_selectionHighlight.setSize(Vector2f(m_gridSize, m_gridSize));
	return true;
}

bool Editor::update(int deltaTime) {
	float x = m_mousePos->x - m_mousePos->x % m_gridSize;
	float y = m_mousePos->y - m_mousePos->y % m_gridSize;
	m_selectionHighlight.setPosition(Vector2f(x, y));
	return true;
}

void Editor::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_block);
	target.draw(m_selectionHighlight);
}
