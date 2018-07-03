#include "Map.h"
#include <fstream>
#include <iostream>


Map::Map() {
	m_name = "map1";
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

void Map::save()
{
	ofstream output;
	string path = "assets\\maps\\" + m_name + ".txt";
	output.open(path, fstream::out);
	if (output.good()) {
		for (MapObject* mapObject : m_mapObjects)
		{
			output << mapObject->getSaveString() << endl;
		}
		cout << "Map " << m_name << " saved." << endl;
	}
	else
	{
		cout << "Failed to save a map" << endl;
	}
	output.close();
}

void Map::load(string name)
{
	m_name = name;
	string path = "assets\\maps\\" + name + ".txt";
	ifstream input(path, ifstream::in);
	MapObject* mapObject;
	while((mapObject = MapObject::load(input)) != nullptr)
	{
		m_mapObjects.push_back(mapObject);
	}
}

void Map::draw(RenderTarget& target, RenderStates states) const {
	for (MapObject* mapObject : m_mapObjects) {
		target.draw(*mapObject);
	}
}
