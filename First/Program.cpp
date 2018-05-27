#include "Program.h"



Program::Program(sf::Vector2i* mousePos) {
	m_editor = new Editor(m_mousePos);
}


Program::~Program() {
}

bool Program::init() {
	m_editor->init();
	return true;
}

bool Program::update(int deltaTime) {
	return true;
}

void Program::draw(RenderTarget& target, RenderStates states) const {
	target.draw(*m_editor);
}

