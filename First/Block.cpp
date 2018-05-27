#include "Block.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"



Block::Block() {
}


Block::~Block() {
}

void Block::initFrame(Frame& frame) {
	Texture* texture = new Texture();
	texture->loadFromFile("res/block.png");
	Sprite* sprite = new Sprite(*texture);
	m_frame.Add(*sprite);
}