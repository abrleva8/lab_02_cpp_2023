#include <filesystem>
#include <fstream>
#include <string>

#include "file_input.h"

FileInput::FileInput() {
	this->is_file_input_ = true;
}

bool FileInput::read_data_from_file(std::ifstream& file, Board& board) {
	std::vector<std::string> cells;
	while (!file.eof()) {
		std::string str;
		std::getline(file, str);
		if (!check_string(str)) {
			std::cerr << "The file has unreadable symbols!";
			return false;
		}

		cells.emplace_back(str);
	}

	const size_t size = cells.size();
	for (const auto& cell: cells) {
		if (cell.length() != size) {
			std::cerr << "The size of data is bad!";
			return false;
		}
	}

	board = Board(cells);
	board.set_size(size);
	return true;
}

bool FileInput::read(Board& board) {
	std::cout << "Enter the filepath please:" << std::endl;
	std::string filepath;
	std::getline(std::cin, filepath);

	if (std::ifstream file(filepath); file.is_open()) {
		if (std::error_code ec; !std::filesystem::is_regular_file(filepath, ec)) {
			std::cerr << "Sorry, there is a problem with file." << std::endl;
			file.close();
			return false;
		}
		return read_data_from_file(file, board);
	} else {
		std::cerr << "Sorry, the file can't be opened." << std::endl;
		file.close();
		return false;
	}
}