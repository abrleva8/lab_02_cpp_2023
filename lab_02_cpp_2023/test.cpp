#include "test.h"
#include "life.h"

int Test::check_in() {
	auto simulator = std::make_unique<Simulator>();
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		simulator->set_board(data_[i]);
		simulator->next_generation();
		auto predict = simulator->get_board();
		if (predict != answers_[i]) {
			std::cout << "Right answer:" << std::endl;
			answers_[i].print_board();
			std::cout << std::endl;

			std::cout << "Your answer:" << std::endl;
			predict.print_board();
			std::cout << std::endl;
			return i;
		}
	}
	
	return -1;
}


bool Test::get_is_success() const {
	return this->is_success_;
}

Test::Test() {
	std::vector<std::string> cells;
	std::vector<std::string> cells_answers;
	cells.emplace_back("*");
	cells_answers.emplace_back("-");
	data_[0] = Board(cells);
	answers_[0] = Board(cells_answers);

	cells.clear();
	cells_answers.clear();

	cells.emplace_back("_*");
	cells.emplace_back("_*");
	cells_answers.emplace_back("__");
	cells_answers.emplace_back("__");
	data_[1] = Board(cells);
	answers_[1] = Board(cells_answers);

	cells.clear();
	cells_answers.clear();

	cells.emplace_back("___");
	cells.emplace_back("*__");
	cells.emplace_back("__*");
	cells_answers.emplace_back("___");
	cells_answers.emplace_back("___");
	cells_answers.emplace_back("___");
	data_[2] = Board(cells);
	answers_[2] = Board(cells_answers);


	cells.clear();
	cells_answers.clear();

	cells.emplace_back("__**");
	cells.emplace_back("__*_");
	cells.emplace_back("_**_");
	cells.emplace_back("***_");
	cells_answers.emplace_back("__**");
	cells_answers.emplace_back("____");
	cells_answers.emplace_back("*__*");
	cells_answers.emplace_back("*_*_");
	data_[3] = Board(cells);
	answers_[3] = Board(cells_answers);


	cells.clear();
	cells_answers.clear();

	cells.emplace_back("__***");
	cells.emplace_back("*_*__");
	cells.emplace_back("_*___");
	cells.emplace_back("__*_*");
	cells.emplace_back("_**__");
	cells_answers.emplace_back("_***_");
	cells_answers.emplace_back("__*__");
	cells_answers.emplace_back("_***_");
	cells_answers.emplace_back("__**_");
	cells_answers.emplace_back("_***_");
	data_[4] = Board(cells);
	answers_[4] = Board(cells_answers);
}

void Test::start() {
	if (const int result = check_in(); result == -1) {
		std::cout << "The testing has passed successfully!" << std::endl;
	} else {
		std::cout << "The program was failed in the test with number " << result + 1 << std::endl;
		is_success_ = false;
	}
	std::cout << std::endl;
}
