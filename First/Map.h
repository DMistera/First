#pragma once
#include "MapObject.h"
#include <vector>
class Map {
public:
	Map();
	~Map();
	vector<MapObject> m_mapObjects;
};

