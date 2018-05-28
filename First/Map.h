#pragma once
#include "MapObject.h"
#include <vector>
class Map : public Drawable{
public:
	Map();
	~Map();
	void addObject(MapObject* mapObject);
	void remove(MapObject* mapObject);
	list<MapObject*> getMapObjects();
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	list<MapObject*> m_mapObjects;
};

