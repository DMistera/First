#include "MainWindow.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Mouse.hpp"
#include "Program.h"

Vector2i MainWindow::SCREEN_SIZE = Vector2i(800, 600);

MainWindow::MainWindow() {
}


MainWindow::~MainWindow() {
}

void MainWindow::start() {
	RenderWindow window(VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "SFML");
	Vector2i mousePos = Mouse::getPosition(window);
	Program program;
	program.init(&mousePos);
	int elapedTime = 0;
	while (window.isOpen()) {
		clock_t begin = clock();
		program.update(elapedTime);
		Event event;
		window.pollEvent(event);
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
