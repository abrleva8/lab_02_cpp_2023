#ifndef _INPUT_H_
#define _INPUT_H_

#include "board.h"

// ����������� ����� ����������� ������ �������
class Input {
protected:
	bool is_file_input_ = false;
	const int MAX_SIZE = 20;
public:
	// �������� ������:
	// 1 - �������� � ���� @text - �����
	// 2 - ������� ������� ��� ���
	virtual bool read(Board& board) = 0;

	[[nodiscard]] bool get_is_file_input() const;

	static bool check_string(const std::string& str);

	// ����������� ����������
	virtual ~Input() = default;
};

#endif