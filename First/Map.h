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
	void save();
	void load(string name);
	static const int BLOCK_SIZE = 32;
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	list<MapObject*> m_mapObjects;
	Song m_song;
	string m_name;
};

