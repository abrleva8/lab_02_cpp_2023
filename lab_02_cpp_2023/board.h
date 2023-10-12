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

	int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
	int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

	[[nodiscard]] bool is_correct_cell(int row_index, int col_index) const;

public:
	std::vector<std::vector<CELLTYPE>> cells;
	std::vector<std::vector<int>> cell_neighbour;
	bool operator==(const Board& another_board) const;
	bool operator!=(const Board& another_board) const;
	explicit Board(int size);
	explicit Board(const std::vector<std::string>& cells);
	Board();
	
	[[nodiscard]] int count_cell_neighbour(int row_index, int col_index) const;
	void print_board(std::ostream* stream = &std::cout) const;
	void print_neighbours();
	void update_cells_neighbour();

	[[nodiscard]] size_t get_size() const {
		return _size;
	}

	void set_size(const size_t size) {
		this->_size = size;
	}
};


#endif