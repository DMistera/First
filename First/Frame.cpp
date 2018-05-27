#include "Frame.h"
#include "SFML/Graphics/RenderTarget.hpp"



Frame::Frame() {
}


Frame::~Frame() {
	for (Drawable* drawable : m_sprites) {
		delete drawable;
	}
}

void Frame::add(Drawable& drawable) {
	m_sprites.push_back(&drawable);
	m_currentImage = &drawable;
}

void Frame::update(unsigned int deltaTime) {

}

void Frame::draw(RenderTarget& target, RenderStates states) const {
	states.transform *= getTransform();
	target.draw(*m_currentImage);
}
