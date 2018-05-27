#pragma once
#include "GameObject.h"
class Block : public GameObject{
public:
	Block();
	~Block();
protected:
	void initFrame(Frame& frame) override;

};

