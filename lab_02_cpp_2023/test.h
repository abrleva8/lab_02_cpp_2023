#ifndef _TEST_H_
#define _TEST_H_

constexpr auto NUMBER_OF_TESTS = 5;

#include "board.h"

class Test {
private:
	//� ���� ���� �������� ������� �� ������ ������������
	bool is_success_;

	//� ���� ���� �������� ������ ��� �����
	Board data_[NUMBER_OF_TESTS];

	//� ���� ���� �������� ������ �� �����
	Board answers_[NUMBER_OF_TESTS];

	//����� ��������� ������ ������ ���  @data_ � ������� � @answers_
	// ���������� ���� � ������� ������
	// ���� ������  ���, �� -1
	[[nodiscard]] int check_in() const;

public:
	// ����� ���������� ���������, ������� �������� � ���� is_success_
	[[nodiscard]] bool get_is_success() const;

	// ����������� ��� ������������� �����
	Test();

	// ����� ����������� ��������� ������������
	void start();
};

#endif