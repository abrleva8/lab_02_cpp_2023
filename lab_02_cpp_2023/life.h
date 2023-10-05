#ifndef _LIFE_H_
#define _LIFE_H_

#include <chrono>
#include <thread>

#include "board.h"

enum Mode {
	ROW = 1,
	STEP,
};

class Simulator {
private:
	Board board;
	Mode mode;

public:
	void set_mode(Mode mode) {
		this->mode = mode;
	}

private:
	const int MAX_STEPS = 100;
protected:
public:
	Simulator(Board board, Mode mode = STEP);
	void print_board();
	void print_neighbours();
	void next_generation();
	void simulate();
};


#endif