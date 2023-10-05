#include "board.h"

#include <algorithm>
#include <memory>
#include <utility>


void Board::update_cells_neighbour() {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cell_neighbour[i][j] = count_cell_neighbour(i, j);
		}
	}
}

int Board::count_cell_neighbour(int row_index, int col_index) {

	int result = 0;

	for (int i = 0; i < 8; i++) {
		int new_dx = row_index + dx[i];
		int new_dy = col_index + dy[i];

		if (is_correct_cell(new_dx, new_dy)) {
			if (cells[new_dx][new_dy] == LIFE) {
				result++;
			}
		}
	}

	return result;
}

bool Board::is_correct_cell(int row_index, int col_index) {
	return 0 <= row_index && row_index < size && 0 <= col_index && col_index < size;
}

void Board::print_board(std::ostream* stream) const {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (cells[i][j] == LIFE) {
				*stream << "*";
			} else {
				*stream << "_";
			}
		}
		if (i != size - 1) {
			*stream << std::endl;
		}
	}
}

void Board::print_neighbours() {
	update_cells_neighbour();

	std::cout << std::endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << cell_neighbour[i][j];
		}
		std::cout << std::endl;
	}
}

int Board::get_size() const {
	return size;
}

bool Board::is_good_data() const {
	for (auto& row : cells) {
		for (const auto celltype : row) {
			if (celltype != '*' || celltype != '_') {
				return false;
			}
		}
	}

	return true;
}

Board::Board(int size) {
	this->size = size;

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
	int size = cells.size();
	cell_neighbour = std::vector<std::vector<int> >(size, std::vector<int>(size));

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
