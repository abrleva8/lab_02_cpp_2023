#include <string>

#include "console_input.h"

ConsoleInput::ConsoleInput() {
	this->is_file_input_ = false;
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