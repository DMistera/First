#pragma once
#include "MapObject.h"

class Block : public MapObject{
public:
	Block();
	~Block();

	virtual void update(unsigned int deltaTime) override;


	virtual GameObject* copy() override;
	MapObjectType getType() override;

protected:
	void initFrame(Frame& frame) override;


	// Inherited via MapObject
	virtual int getBlockWidth() override;

	virtual int getBlockHeigth() override;
};

