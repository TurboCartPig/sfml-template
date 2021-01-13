#include <SFML/Window.hpp>
#include <iostream>

int main() {
	std::cout << "Hello!" << std::endl;

	sf::Window window(sf::VideoMode(400, 300), "Built with cmake!");

	do {
		// Event handling
		sf::Event event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed: window.close(); break;

				default: break;
			}
		}

		window.display();
	} while (window.isOpen());

	return EXIT_SUCCESS;
}
