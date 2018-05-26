#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

using namespace sf;

int main() {
	
	RenderWindow window(VideoMode(800, 600), "SFML");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			window.clear();
			window.display();
		}

	}
	system("PAUSE");
	return 0;
}