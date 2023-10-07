#include <windows.h>

#include <utility>

#include "life.h"
#include "console_input.h"


void Simulator::next_generation() {
	const size_t size = _board.get_size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (const auto neighbors = _board.cell_neighbour[i][j]; neighbors < 2 || neighbors > 3) {
				_board.cells[i][j] = EMPTY;
			} else if (neighbors == 3) {
				_board.cells[i][j] = LIFE;
			}
		}
	}

	_board.update_cells_neighbour();
}

void Simulator::simulate() {
	_history.clear();
	_history.emplace_back(_board);

	if (_mode == ROW) {
		std::cout << "Press key 'space' to espace the loop!" << std::endl;
		for (int i = 0; i < MAX_STEPS; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			if (GetKeyState(VK_SPACE)) {
				std::cout << "Stopped!" << std::endl;
				break;
			}

			print_board();
			print_neighbours();
			_history.emplace_back(_board);
			next_generation();
		}
	} else {
		bool is_continue{ true };
		while (is_continue) {
			print_board();
			print_neighbours();
			_history.emplace_back(_board);
			next_generation();
			std::cout << "Continue? Please enter y/n" << std::endl;
			is_continue = ConsoleInput::is_choice_yes();
		}
	}
	
	std::cout << "The end!";
}

	

Simulator::Simulator(Board board, const Mode mode) {
	this->_board = std::move(board);
	this->_mode = mode;
}

void Simulator::print_board(std::ostream* stream) const {
	_board.print_board(stream);
}

void Simulator::print_neighbours() {
	_board.print_neighbours();
}

void Simulator::print_history(std::ostream* stream) const {
	for (auto &board : _history) {
		board.print_board(stream);
		*stream << std::endl << std::endl;
	}
}
