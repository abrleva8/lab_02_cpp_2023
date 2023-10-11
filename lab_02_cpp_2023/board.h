#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>

enum CELLTYPE {
	EMPTY,
	LIFE
};

class Board {
private:
	size_t _size;

	int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
	int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

	[[nodiscard]] bool is_correct_cell(int row_index, int col_index) const;

public:

	bool operator==(const Board& another_board);
	bool operator!=(const Board& another_board);
	explicit Board(int size);
	explicit Board(const std::vector<std::string>& cells);
	Board();
	std::vector<std::vector<CELLTYPE>> cells;
	int count_cell_neighbour(int row_index, int col_index) const;
	void print_board(std::ostream* stream = &std::cout) const;
	void print_neighbours();
	void update_cells_neighbour();
	std::vector<std::vector<int>> cell_neighbour;

	[[nodiscard]] size_t get_size() const {
		return _size;
	}

	void set_size(const size_t size) {
		this->_size = size;
	}
};


#endif