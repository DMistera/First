#include "Song.h"



Song::Song()
{
	
}


Song::~Song()
{
}

bool Song::load(string filename)
{
	if (!m_buffer.loadFromFile(filename))
	{
		return false;
	}
	m_sound.setBuffer(m_buffer);
	return true;
}

void Song::play()
{
	m_sound.play();
}
