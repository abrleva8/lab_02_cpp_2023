#ifndef _LIFE_H_
#define _LIFE_H_

#include <vector>

#include "board.h"



class Simulator {
private:
	Board board;
protected:
public:
	Simulator(Board board);
	void print_board();
	void print_neighbours();
	void next_generation();
};


#endif