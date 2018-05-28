#include "Frame.h"
#include "SFML/Graphics/RenderTarget.hpp"



Frame::Frame() {
}


Frame::~Frame() {
	for (Sprite* drawable : m_sprites) {
		delete drawable;
	}
}

void Frame::add(Sprite& sprite) {
	m_sprites.push_back(&sprite);
	m_size.x = sprite.getLocalBounds().width;
	m_size.y = sprite.getLocalBounds().height;
	//temp
	m_currentSprite = &sprite;
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
	target.draw(*m_currentSprite, states);
}
