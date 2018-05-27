#pragma once
#include "GameObject.h"
class Block : public GameObject{
public:
	Block();
	~Block();

	virtual void update(unsigned int deltaTime) override;

protected:
	void initFrame(Frame& frame) override;

};

