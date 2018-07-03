#include "EditorUI.h"




EditorUI::EditorUI() {
}

EditorUI::~EditorUI() {
}

bool EditorUI::init(Vector2i* mousePos) {
	m_mousePos = mousePos;
	m_layoutWidth = 20;
	m_iconSize = 64;

	m_saveButtonPressed = false;

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

bool EditorUI::update(int deltaTime, bool& saveCommand) {

	if (Mouse::isButtonPressed(Mouse::Left)) {
		MapObject* t = getTemplateFromCursor();
		if (t != nullptr) {
			m_selectedTemplate = (MapObject*)t->copy();
			
		}
	}
	if (m_selectedTemplate != nullptr) {
		m_selectedTemplate->getFrame().setPosition((Vector2f)*m_mousePos);
	}

	saveCommand = false;
	bool f1 = sf::Keyboard::isKeyPressed(Keyboard::Key::F1);
	if(f1 && !m_saveButtonPressed)
	{
		saveCommand = true;
		m_saveButtonPressed = true;
	}
	else if(!f1)
	{
		m_saveButtonPressed = false;
	}

	return true;
}

MapObject* EditorUI::getSelectedTemplate() {
	return m_selectedTemplate;
}

void EditorUI::draw(RenderTarget& target, RenderStates states) const {
	State::draw(target, states);
	target.draw(m_templateLayout);
	for (MapObject* mapObject : m_templates) {
		target.draw(*mapObject);
	}
	if (m_selectedTemplate != nullptr) {
		target.draw(*m_selectedTemplate);
	}
}
MapObject * EditorUI::getTemplateFromCursor()
{
	for (MapObject* mapObject : m_templates) {
		if (mapObject->getFrame().contains((Vector2f)*m_mousePos)) {
			return mapObject;
		}
	}
	return nullptr;
}
