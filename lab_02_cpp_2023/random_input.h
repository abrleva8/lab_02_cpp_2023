#ifndef _RANDOM_INPUT_H_
#define _RANDOM_INPUT_H_

#include "input.h"
// #include "text_analyzer.h"

// �����, ����������� ������ �� ����� ������
class RandomInput final : public Input {
private:

	// ������� ������ �� �����, �� ���������� �����
	// bool read_data_from_file(std::ifstream& file, Text& text) const;

public:
	RandomInput();
	// ���������� ������ ������ @Input
	bool read(Board& board) override;

};

#endif