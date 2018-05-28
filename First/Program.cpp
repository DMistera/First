#include "Program.h"



Program::Program() {
}


Program::~Program() {
}

bool Program::init(Vector2i* mousePos) {
	m_editor.init(mousePos);
	return true;
}

bool Program::update(int deltaTime) {
	m_editor.update(deltaTime);
	return true;
}

void Program::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_editor);
}

