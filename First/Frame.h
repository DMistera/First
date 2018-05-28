#pragma once
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include <list>
#include "SFML/Graphics/Sprite.hpp"

using namespace sf;
using namespace std;

class Frame : public Drawable , public Transformable{
public:
	Frame();
	~Frame();
	void add(Sprite& drawable);
	void update(unsigned int deltaTime);
	float getWidth();
	float getHeight();
	bool contains(Vector2f v);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	Sprite * m_currentSprite;
	list<Sprite*> m_sprites;
	Vector2f m_size;
};