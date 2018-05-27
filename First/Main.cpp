#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Program.h"

using namespace sf;

int main() {
	
	RenderWindow window(VideoMode(800, 600), "SFML");
	Vector2i mousePos = Mouse::getPosition(window);
	Program program(&mousePos);
	program.init();
	int elapedTime = 0;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			program.update(elapedTime);

			clock_t begin = clock();
			mousePos = Mouse::getPosition(window);
			if (event.type == Event::Closed) {
				window.close();
			}
			window.clear();
			window.draw(program);
			window.display();
			clock_t end = clock();
			elapedTime = int(end - begin);
		}
	}
	system("PAUSE");
	return 0;
}