#include "test.h"

int Test::check_in() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		if (std::unique_ptr<int[]> ans = this->data_[i].get_info(); ans[j] != answers_[i][j]) {
			std::cout << "The parameter with number " << j << " is wrong." << std::endl;
			std::cout << "Right answer = " << answers_[i][j] << std::endl;
			std::cout << "Your answer = " << ans[j] << std::endl;
			return i;
		}
	}
	//delete[] this->answers_;
	return -1;
}

bool Test::get_is_success() const {
	return this->is_success_;
}

Test::Test() {
	std::vector<std::string> cells;
	std::vector<std::string> cells_answers;
	cells.emplace_back("*");
	cells.emplace_back("_");
	data_[0] = Board(cells);
	answers_[0] = Board(cells_answers);
}
