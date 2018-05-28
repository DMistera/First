#pragma once
#include "SFML/System/Vector2.hpp"

using namespace sf;


class MainWindow {
public:
	MainWindow();
	~MainWindow();
	void start();
	static Vector2i SCREEN_SIZE;
};

