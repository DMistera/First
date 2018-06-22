#include "State.h"

//This may be dangerous
#include "MainWindow.h"


State::State() {
	m_windowArea = FloatRect(Vector2f(), (Vector2f)MainWindow::SCREEN_SIZE);
	m_view.setSize(m_windowArea.width, m_windowArea.height);
	m_view.setCenter(m_windowArea.width / 2, m_windowArea.height / 2);
}


State::~State() {
}

sf::Vector2f State::getViewOffset() {
	return Vector2f();
}

sf::Vector2f State::convertFromCursor(Vector2i mousePosition)
{
	return (Vector2f)mousePosition + m_view.getCenter() - Vector2f(m_windowArea.width / 2, m_windowArea.height / 2);
}

void State::draw(RenderTarget& target, RenderStates states) const {
	target.setView(m_view);
}