#include "MapObject.h"
#include <string>
#include <fstream>

#include "Block.h"
#include "Map.h"

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

string MapObject::getSaveString()
{
	return std::to_string(getType()) + " " + std::to_string(m_mapPosition.x) + " " + std::to_string(m_mapPosition.y);
}

MapObject* MapObject::load(ifstream& stream)
{
	string s1;
	int x;
	int y;
	if(stream >> s1 >> x >> y)
	{
		MapObjectType type = static_cast<MapObjectType>(stoi(s1));
		MapObject* result = nullptr;
		switch (type) {
		case BLOCK: result = new Block();
		default:;
		}
		result->init();
		result->setMapPosition(Vector2i(x, y));
		return result;
	}
	else
	{
		return nullptr;
	}
}

Vector2i MapObject::getMapPosition()
{
	return m_mapPosition;
}

void MapObject::setMapPosition(Vector2i v)
{
	m_mapPosition = v;
	m_frame.setPosition(Vector2f(v.x * Map::BLOCK_SIZE, v.y * Map::BLOCK_SIZE));
}

void MapObject::draw(RenderTarget& target, RenderStates states) const {
	target.draw(m_frame);
}
