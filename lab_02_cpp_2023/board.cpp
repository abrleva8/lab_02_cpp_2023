#include "board.h"

#include <algorithm>
#include <memory>

Board::Board(int size) {
	cells.resize(size);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cells[i][j] = EMPTY;
		}
	}
}
