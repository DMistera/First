#pragma once
#include "MapObject.h"
#include <vector>
#include "Song.h"
class Map : public Drawable{
public:
	Map();
	~Map();
	void addObject(MapObject* mapObject);
	void remove(MapObject* mapObject);
	list<MapObject*> getMapObjects();
	void setSong(Song song);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	list<MapObject*> m_mapObjects;
	Song m_song;
};

