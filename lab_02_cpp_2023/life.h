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

public:
	void set_mode(const Mode mode) {
		this->_mode = mode;
	}

private:
	const int MAX_STEPS = 100;
public:
	explicit Simulator(Board board, Mode mode = STEP);
	void print_board(std::ostream* stream = &std::cout) const;
	void print_neighbours();
	void print_history(std::ostream* stream = &std::cout) const;
	void next_generation();
	void simulate();
};


#endif