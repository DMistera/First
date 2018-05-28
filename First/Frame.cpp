#include "Frame.h"
#include "SFML/Graphics/RenderTarget.hpp"



Frame::Frame() {
}


Frame::~Frame() {
	for (Drawable* drawable : m_sprites) {
		delete drawable;
	}
}

void Frame::add(Drawable& drawable, FloatRect bounds) {
	m_sprites.push_back(&drawable);
	m_size.x = bounds.width;
	m_size.y = bounds.height;
	//temp
	m_currentImage = &drawable;
}

void Frame::update(unsigned int deltaTime) {

}

float Frame::getWidth()
{
	return m_size.x*this->getScale().x;
}

float Frame::getHeight()
{
	return m_size.y*this->getScale().x;
}

bool Frame::contains(Vector2f v)
{
	if (v.x < this->getPosition().x || this->getPosition().x + getWidth() < v.x )
		return false;
	if (v.y < this->getPosition().y || this->getPosition().y + getHeight() < v.y)
		return false;
	return true;
}

void Frame::draw(RenderTarget& target, RenderStates states) const {
	states.transform *= getTransform();
	target.draw(*m_currentImage, states);
}
