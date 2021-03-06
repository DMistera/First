#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Drawable.hpp"

using namespace sf;

class State : public Drawable {
public:
	State();
	~State();
	Vector2f getViewOffset();
	Vector2f convertFromCursor(Vector2i mousePosition);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	View m_view;
	FloatRect m_windowArea;
};

