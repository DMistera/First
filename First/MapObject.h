#pragma once
#include "GameObject.h"

class MapObject :
	public GameObject {
public:
	MapObject();
	MapObject(MapObject& copy);
	~MapObject();
	virtual int getBlockWidth() = 0;
	virtual int getBlockHeigth() = 0;
	virtual void init() override;
	Frame& getFrame();
	string getSaveString();
	static MapObject* load(ifstream& stream);
	enum MapObjectType
	{
		BLOCK
	};
	Vector2i getMapPosition();
	virtual MapObjectType getType() = 0;
	void setMapPosition(Vector2i v);
protected:
	virtual void initFrame(Frame& frame) = 0;
	Frame m_frame;
	Vector2i m_mapPosition;
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};

