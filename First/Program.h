#pragma once
#include "State.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "EditorUI.h"
#include "Editor.h"
#include "Gameplay.h"

using namespace sf;

class Program : public State {
public:
	
	Program();
	~Program();

	// Inherited via State
	bool init(Vector2i* mousePos);
	bool update(int deltaTime);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	Editor m_editor;
	Gameplay m_gameplay;
};

