#include "Editor.h"



Editor::Editor() {
}


Editor::~Editor() {
}

bool Editor::init(Vector2i* mousePos) {
	 m_editorUI.init(mousePos);
	 Map* map = new Map();
	 m_editorMap.init(mousePos,*map);
	 return true;
}

bool Editor::update(int deltaTime) {
	 m_editorUI.update(deltaTime);
	 MapObject* selectedTemplate = m_editorUI.getSelectedTemplate();
	 m_editorMap.update(deltaTime, selectedTemplate);
	 return true;
}

void Editor::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_editorMap);
	target.draw(m_editorUI);
}
