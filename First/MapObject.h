#pragma once
#include "GameObject.h"
class MapObject :
	public GameObject {
public:
	MapObject();
	~MapObject();
	virtual int getBlockWidth() = 0;
	virtual int getBlockHeigth() = 0;
};

