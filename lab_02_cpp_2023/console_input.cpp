#include <string>

#include "console_input.h"

ConsoleInput::ConsoleInput() {
	this->is_file_input_ = false;
}

bool ConsoleInput::read(Board& board) {
	std::cout << "Enter the size of the board: ";
	int size = get_number(1, 10);

	std::cout << "1 is Life, 0 is Not Life" << std::endl;
	board = Board(size);

	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << " row: ";
		for (int j = 0; j < size; j++) {
			int number = get_number(0, 1);
			board.cells[i][j] = static_cast<CELLTYPE>(number);
		}
	}
	return true;
}


bool ConsoleInput::is_choice_yes() {
	std::string save{};
	std::getline(std::cin, save);
	while (save != "y" && save != "n") {
		std::cout << "Wrong input. Please input y/n" << std::endl;
		std::getline(std::cin, save);
	}
	return save != "n";
}