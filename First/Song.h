#pragma once
#include <string>
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;

class Song {
public:
	Song();
	~Song();
	bool load(string filename);
	void play();
private:
	string m_artist;
	string m_title;
	SoundBuffer m_buffer;
	Sound m_sound;
};

