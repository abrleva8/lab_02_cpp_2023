#ifndef _INPUT_H_
#define _INPUT_H_

#include "board.h"

// ����������� ����� ����������� ������ �������
class Input {
protected:
	bool is_file_input_ = false;
public:
	// �������� ������:
	// 1 - �������� � ���� @text - �����
	// 2 - ������� ������� ��� ���
	virtual bool read(Board& board) = 0;

	[[nodiscard]] bool get_is_file_input() const;

	bool check_string(std::string str);

	// ����������� ����������
	virtual ~Input() = default;
};

#endif