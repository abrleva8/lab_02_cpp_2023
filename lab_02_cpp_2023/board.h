#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <iostream>

enum CELLTYPE {
	EMPTY,
	LIFE
};

class Board {
private:
	int size;
	
	int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
	int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

	bool is_correct_cell(int row_index, int col_index);
protected:

public:
	Board(int size);
	Board();
	std::vector<std::vector<CELLTYPE>> cells;
	int count_cell_neighbour(int row_index, int col_index);
	void print_board(std::ostream* stream = &std::cout);
	void print_neighbours();
	void update_cells_neighbour();
	std::vector<std::vector<int>> cell_neighbour;
	int get_size() const;
};


#endif