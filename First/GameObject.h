#pragma once
#include "Frame.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

class GameObject : public Drawable{
public:
	GameObject();
	~GameObject();
	void init();
protected:
	virtual void initFrame(Frame& frame) = 0;
	Frame m_frame;

	void draw(RenderTarget& target, RenderStates states) const override;

};

