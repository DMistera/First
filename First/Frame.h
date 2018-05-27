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
	void add(Drawable& drawable);
	void update(unsigned int deltaTime);
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	Drawable* m_currentImage;
	list<Drawable*> m_sprites;
};