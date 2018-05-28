#pragma once
#include "Frame.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

class GameObject : public Drawable{
public:
	GameObject();
	GameObject(GameObject& copy);
	~GameObject();
	virtual void init();
	virtual void update(unsigned int deltaTime) = 0;
	virtual GameObject* copy() = 0;
protected:

	void draw(RenderTarget& target, RenderStates states) const override;

};

