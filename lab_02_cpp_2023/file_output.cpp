#include <iostream>
#include <fstream>
#include <filesystem>
#include <utility>

#include "file_output.h"
#include "console_input.h"

void FileOutput::try_overwrite_file(std::string& filename) const {
	bool is_to_overwrite = false;

	while (is_file_exist(filename) && !is_to_overwrite) {
		if (std::error_code ec; !std::filesystem::is_regular_file(filename, ec)) {
			return;
		}
		std::cout << "The file with same name exists. Are you sure to want overwrite the file? Input please y/n." << std::endl;
		ConsoleInput ci;
		is_to_overwrite = ci.is_choice_yes();
		if (!is_to_overwrite) {
			std::cout << "Please input the filename:" << std::endl;
			std::getline(std::cin, filename);
		}
	}
}

bool FileOutput::is_file_exist(const std::string& filename) {
	const std::ifstream infile(filename);
	return infile.good();
}

void FileOutput::write_input_data_to_file(std::ofstream& fout, Board board) {
	board.print_board(&fout);
}

bool FileOutput::save_input_data_to_file(Board board) const {
	std::cout << "Please, input the filename:" << std::endl;
	std::string filename;
	getline(std::cin, filename);
	try_overwrite_file(filename);
	std::ofstream fout(filename);
	if (fout.is_open()) {
		if (std::error_code ec; !std::filesystem::is_regular_file(filename, ec)) {
			std::cerr << "Sorry, there is a problem with file." << std::endl;
			return false;
		}
		write_input_data_to_file(fout, std::move(board));
	} else {
		fout.close();
		return false;
	}
	fout.close();
	return true;
}

void FileOutput::save_input_data(const Board& board) const {
	std::cout << "Do you want to save input data to file? Input please y/n." << std::endl;

	if (const ConsoleInput ci; ci.is_choice_yes()) {
		bool is_success = save_input_data_to_file(board);

		while (!is_success) {
			std::cerr << "The data didn't save! Try again!" << std::endl;
			is_success = save_input_data_to_file(board);
		}

		std::cout << "The data saved successfully!" << std::endl;
	}
}