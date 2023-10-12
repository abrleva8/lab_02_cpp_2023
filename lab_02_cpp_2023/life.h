#ifndef _LIFE_H_
#define _LIFE_H_

#include <chrono>

#include "board.h"

enum Mode {
	ROW = 1,
	STEP,
};

class Simulator {
private:
	Board _board;
	std::vector<Board> _history;
	Mode _mode;
	const int MAX_STEPS{100};

public:
	void set_board(const Board& board) {
		_board = board;
	}

	[[nodiscard]] Board get_board() const {
		return _board;
	}

	void set_mode(const Mode mode) {
		this->_mode = mode;
	}

	explicit Simulator(Mode mode = STEP);
	explicit Simulator(Board board, Mode mode = STEP);
	void print_board(std::ostream* stream = &std::cout) const;
	void print_neighbours();
	void print_history(std::ostream* stream = &std::cout) const;
	void next_generation();
	void do_work();
	void simulate();
};


#endif