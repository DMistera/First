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
protected:
	virtual void initFrame(Frame& frame) = 0;
	Frame m_frame;
	Vector2i m_blockPosition;
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};

