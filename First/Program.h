#pragma once
#include "State.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "Editor.h"

using namespace sf;

class Program : public State {
public:
	Program(sf::Vector2i* mousePos);
	~Program();

	// Inherited via State
	virtual bool init() override;
	virtual bool update(int deltaTime) override;
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	Vector2i* m_mousePos;
	Editor* m_editor;

};

