#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

enum CELLTYPE {
	EMPTY,
	LIFE
};

class Board {
private:
	std::vector<std::vector<CELLTYPE>> cells;
protected:

public:
	Board(int size);
};


#endif