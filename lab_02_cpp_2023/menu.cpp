#include <iostream>

#include "menu.h"
// #include "text_analyzer.h"
#include "console_input.h"
#include "file_input.h"
#include "random_input.h"
// #include "file_output.h"
// #include "test.h"

void greetings() {
	std::cout << "This is the second laboratory task of the first variation. "
		"The author is Levon Abramyan, Group 404, Course 4th" << std::endl << std::endl;

	std::cout << "The problem is: simulate the Game of Life." << std::endl << std::endl;

	std::cout << "" << std::endl << std::endl;
}

void print_menu() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter 1 to read data from console." << std::endl;
	std::cout << "Enter 2 to read data from file." << std::endl;
	std::cout << "Enter 3 to set random data." << std::endl;
	std::cout << "Enter 4 to test program." << std::endl;
	std::cout << "Enter 0 to exit." << std::endl;
}

void interface_menu() {
	bool is_restart = true;
	ConsoleInput ci;
	std::unique_ptr<Input> input;


	do {
		// const FileOutput fo;
		print_menu();
		switch (const int choice = ci.get_number(static_cast<int> (EXIT), static_cast<int> (TEST)); choice) {
		case EXIT:
			std::cout << "Your choice is EXIT" << std::endl;
			is_restart = false;
			continue;
		case CONSOLE: {
			input = std::make_unique<ConsoleInput>();
		}
			break;
		case FILES: {
			input = std::make_unique<FileInput>();
		}
			break;
		case RANDOM: {
			input = std::make_unique<RandomInput>();
		}
			break;
		case TEST: {
			std::cout << "No test yet! Sorry! :(";
		}
			break;
		default:
			break;
		}

	} while (is_restart);
}
