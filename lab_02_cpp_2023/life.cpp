#include "life.h"


void Simulator::next_generation() {
	int size = board.get_size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			auto neighbors = board.cell_neighbour[i][j];
			if (neighbors < 2 || neighbors > 3) {
				board.cells[i][j] = EMPTY;
			} else if (neighbors == 3) {
				board.cells[i][j] = LIFE;
			}
		}
	}

	board.update_cells_neighbour();
}

Simulator::Simulator(Board board) {
	this->board = board;
}

void Simulator::print_board() {
	board.print_board();
}

void Simulator::print_neighbours() {
	board.print_neighbours();
}
