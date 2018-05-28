#include "MapObject.h"



MapObject::MapObject() {
}


MapObject::MapObject(MapObject& copy) : GameObject(copy) {
	m_frame = copy.getFrame();
}

MapObject::~MapObject() {
}

void MapObject::init() {
	initFrame(m_frame);
}

Frame& MapObject::getFrame() {
	return m_frame;
}

void MapObject::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_frame);
}
