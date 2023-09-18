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
	std::vector<std::vector<int>> cell_neighbour;
	
	int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
	int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

	void update_cells_neighbour();
	int count_cell_neighbour(int row_index, int col_index);
	bool is_correct_cell(int row_index, int col_index);
protected:

public:
	Board(int size);
	Board();
	std::vector<std::vector<CELLTYPE>> cells;
	void print_board();
	void print_neighbours();
};


#endif