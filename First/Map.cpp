#include "Map.h"



Map::Map() {
}


Map::~Map() {
}

void Map::addObject(MapObject* mapObject) {
	m_mapObjects.push_back(mapObject);
}

void Map::draw(RenderTarget& target, RenderStates states) const {
	for (MapObject* mapObject : m_mapObjects) {
		target.draw(*mapObject);
	}
}
