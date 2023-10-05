#include <windows.h>

#include "life.h"
#include "console_input.h"


void Simulator::next_generation() {
	const int size = board.get_size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (const auto neighbors = board.cell_neighbour[i][j]; neighbors < 2 || neighbors > 3) {
				board.cells[i][j] = EMPTY;
			} else if (neighbors == 3) {
				board.cells[i][j] = LIFE;
			}
		}
	}

	board.update_cells_neighbour();
}

void Simulator::simulate() {
	if (mode == ROW) {
		std::cout << "Press key 'space' to espace the loop!" << std::endl;
		for (int i = 0; i < MAX_STEPS; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			if (GetKeyState(VK_SPACE)) {
				std::cout << "Stopped!" << std::endl;
				break;
			} else {
				print_board();
				print_neighbours();
				next_generation();
			}
		}
	} else {
		bool is_continue{ true };
		while (is_continue) {
			print_board();
			print_neighbours();
			next_generation();
			std::cout << "Continue? Please enter y/n" << std::endl;
			is_continue = ConsoleInput::is_choice_yes();
		}
	}
	
	std::cout << "The end!";
}

	

Simulator::Simulator(Board board, Mode mode) {
	this->board = board;
	this->mode = mode;
}

void Simulator::print_board() {
	board.print_board();
}

void Simulator::print_neighbours() {
	board.print_neighbours();
}
