#ifndef _RANDOM_INPUT_H_
#define _RANDOM_INPUT_H_

#include "input.h"
// #include "text_analyzer.h"

// Класс, реализующий чтение из файла текста
class RandomInput final : public Input {
private:

	// Процесс чтения из файла, на корректном файле
	// bool read_data_from_file(std::ifstream& file, Text& text) const;

public:
	RandomInput();
	// Реализация метода класса @Input
	bool read(Board& board) override;

};

#endif