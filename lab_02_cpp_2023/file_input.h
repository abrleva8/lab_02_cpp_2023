#ifndef _FILE_INPUT_H_
#define _FILE_INPUT_H_

#include <iostream>

#include "input.h"
// #include "text_analyzer.h"

// �����, ����������� ������ �� ����� ������
class FileInput final : public Input {
private:

	// ������� ������ �� �����, �� ���������� �����
	static bool read_data_from_file(std::ifstream& file, Board& board);

public:
	FileInput();
	// ���������� ������ ������ @Input
	bool read(Board& board) override;

};

#endif