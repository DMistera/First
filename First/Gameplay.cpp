#include "Gameplay.h"



Gameplay::Gameplay()
{
}


Gameplay::~Gameplay()
{
}

void Gameplay::update()
{

}

void Gameplay::init()
{
	Song s;
	s.load("res/MEPHISTO.ogg");
	m_map.setSong(s);

}

void Gameplay::draw(RenderTarget& target, RenderStates states) const
{
	throw std::logic_error("The method or operation is not implemented.");
}
