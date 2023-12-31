#include <iostream>

#include "menu.h"
#include "board.h"
#include "console_input.h"
#include "file_input.h"
#include "file_output.h"
#include "life.h"
#include "random_input.h"
#include "test.h"

void greetings() {
	std::cout << "This is the second laboratory task of the first variation. "
		"The author is Levon Abramyan, Group 404, Course 4th" << std::endl << std::endl;

	std::cout << "The problem is: simulate the Game of Life." << std::endl << std::endl;
}

void print_menu() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter 1 to read data from console." << std::endl;
	std::cout << "Enter 2 to read data from file." << std::endl;
	std::cout << "Enter 3 to set random data." << std::endl;
	std::cout << "Enter 4 to test program." << std::endl;
	std::cout << "Enter 0 to exit." << std::endl;
}

void print_menu_mode() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter 1 to print the result every second." << std::endl;
	std::cout << "Enter 2 to print the result step by step." << std::endl;
}

void interface_menu() {
	bool is_restart = true;
	ConsoleInput ci;
	std::unique_ptr<Input> input;


	do {
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
			const auto test = std::make_unique<Test>();

			test->start();

			if (!test->get_is_success()) {
				std::cout << "Sorry, but there is a problem test. The program will be closed." << std::endl;
				return;
			}
			continue;
		}
			break;
		default:
			break;
		}

		std::unique_ptr<Board> board(new Board);
		const bool is_success = input->read(*board);
		board->print_board();
		const bool is_file_input = input->get_is_file_input();

		if (is_success) {
			std::cout << std::endl << "Data read successfully!" << std::endl;
		} else {
			continue;
		}
		if (!is_file_input) {
			FileOutput::save_input_data(*board);
		}
		
		const auto simulator = std::make_unique<Simulator>(*board);

		print_menu_mode();
		switch (const int choice = ci.get_number(static_cast<int> (ROW), static_cast<int> (STEP)); choice) {
			case ROW:{
				simulator->set_mode(ROW);
			}
				break;

			case STEP: {
				simulator->set_mode(STEP);
			}
				break;
			
			default:
				break;
		}

		simulator->simulate();
		FileOutput::save_output_data(*simulator);

	} while (is_restart);
}
