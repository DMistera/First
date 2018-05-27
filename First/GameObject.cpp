#include "GameObject.h"



GameObject::GameObject() {
}


GameObject::~GameObject() {
}

void GameObject::init() {
	initFrame(m_frame);
}

void GameObject::initFrame(Frame& frame) {

}

void GameObject::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_frame);
}
