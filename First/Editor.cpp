#include "Editor.h"




Editor::Editor(Vector2i* mousePos) {

}

Editor::~Editor() {
}

bool Editor::init() {
	m_block.init();
	return true;
}

bool Editor::update(int deltaTime) {
	return true;
}

void Editor::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_block);
}
