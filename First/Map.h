#pragma once
#include "MapObject.h"
#include <vector>
class Map : public Drawable{
public:
	Map();
	~Map();
	void addObject(MapObject* mapObject);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	vector<MapObject*> m_mapObjects;
};

