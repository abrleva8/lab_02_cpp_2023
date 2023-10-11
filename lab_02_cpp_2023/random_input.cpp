#include "random_input.h"

RandomInput::RandomInput() {
	this->is_file_input_ = false;
}

bool RandomInput::read(Board& board) {
	//const int size = rand() % MAX_SIZE + 1;
	const int size = 5;
	std::cout << "The size of the board is: " << size << std::endl;

	board = Board(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int number = rand() % 2;
			board.cells[i][j] = static_cast<CELLTYPE>(number);
		}
	}

	return true;
}
