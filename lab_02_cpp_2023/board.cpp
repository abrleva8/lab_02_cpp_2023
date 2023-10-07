#include "board.h"

#include <algorithm>
#include <memory>
#include <utility>


void Board::update_cells_neighbour() {

	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size; ++j) {
			cell_neighbour[i][j] = count_cell_neighbour(i, j);
		}
	}
}

int Board::count_cell_neighbour(const int row_index, const int col_index) {

	int result = 0;

	for (int i = 0; i < 8; i++) {
		const int new_dx = row_index + dx[i];
		const int new_dy = col_index + dy[i];

		if (is_correct_cell(new_dx, new_dy)) {
			if (cells[new_dx][new_dy] == LIFE) {
				result++;
			}
		}
	}

	return result;
}

bool Board::is_correct_cell(const int row_index, const int col_index) const {
	return 0 <= row_index && row_index < _size && 0 <= col_index && col_index < _size;
}

void Board::print_board(std::ostream* stream) const {

	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size; ++j) {
			if (cells[i][j] == LIFE) {
				*stream << "*";
			} else {
				*stream << "_";
			}
		}
		if (i != _size - 1) {
			*stream << std::endl;
		}
	}
}

void Board::print_neighbours() {
	update_cells_neighbour();

	std::cout << std::endl;
	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size; ++j) {
			std::cout << cell_neighbour[i][j];
		}
		std::cout << std::endl;
	}
}

Board::Board(const int size) {
	this->_size = size;

	cells = std::vector<std::vector<CELLTYPE> >(size, std::vector<CELLTYPE>(size));
	cell_neighbour = std::vector<std::vector<int> >(size, std::vector<int>(size));

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cells[i][j] = EMPTY;
			cell_neighbour[i][j] = 0;
		}
	}
}

Board::Board(const std::vector<std::string>& cells) {
	this->cells.clear();
	const size_t size = cells.size();
	cell_neighbour = std::vector(size, std::vector<int>(size));

	for (int i = 0; i < cells.size(); ++i) {
		this->cells.emplace_back();
		for (int j = 0; j < cells[i].length(); ++j) {
			auto cell_type = cells[i][j] == '*' ? LIFE : EMPTY;
			this->cells[i].emplace_back(cell_type);

			cell_neighbour[i][j] = 0;
		}
	}
}

Board::Board() = default;
