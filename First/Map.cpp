#include "Map.h"



Map::Map() {
}


Map::~Map() {
}

void Map::addObject(MapObject* mapObject) {
	m_mapObjects.push_back(mapObject);
}

void Map::remove(MapObject* mapObject) {
	m_mapObjects.remove(mapObject);
}

std::list<MapObject*> Map::getMapObjects() {
	return m_mapObjects;
}

void Map::setSong(Song song)
{
	m_song = song;
}

void Map::draw(RenderTarget& target, RenderStates states) const {
	for (MapObject* mapObject : m_mapObjects) {
		target.draw(*mapObject);
	}
}
