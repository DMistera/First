#pragma once
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include <list>

using namespace sf;
using namespace std;

class Frame : public Drawable , public Transformable{
public:
	Frame();
	~Frame();
	void add(Drawable& drawable, FloatRect bounds);
	void update(unsigned int deltaTime);
	float getWidth();
	float getHeight();
	bool contains(Vector2f v);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	Drawable* m_currentImage;
	list<Drawable*> m_sprites;
	Vector2f m_size;
};