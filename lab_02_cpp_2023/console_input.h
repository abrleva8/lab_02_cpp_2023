#ifndef _CONSOLE_INPUT_H_
#define _CONSOLE_INPUT_H_

#include <iostream>
#include <string>

#include "input.h"

class ConsoleInput final : public Input {
public:
	ConsoleInput();
	// ���������� ������ �� ������ @Input
	bool read(Board& board) override;

	// ���������� � ������������ "��" ��� "���"
	// ���� ������� 'y' -  ���������� @true
	// ���� ������� 'n' -  ���������� @false
	[[nodiscard]] static bool is_choice_yes();

	// ��������� ����� ������� ���������� �����
	// �������� � �������� ������ ������
	template<class Type>
	Type get_number();

	// ��������� ����� ������� ���������� ����� c ���������� [@min; @max]
	// �������� � �������� ������ ������
	template<class Type>
	Type get_number(Type min, Type max, std::string message="");
};

template<typename Type>
Type ConsoleInput::get_number() {
	Type input;
	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Wrong input, try again." << std::endl;
		std::cin >> input;
	}

	std::cin.ignore(INT_MAX, '\n');

	return input;
}

template<typename Type>
Type ConsoleInput::get_number(Type min, Type max, const std::string message) {
	Type result = get_number<Type>();
	while (result > max || result < min) {
		std::cout << "Your number should be between " << min << " and " << max << std::endl;
		std::cout << "Try again, please!" << std::endl;
		if (!message.empty()) {
			std::cout << message;
		}
		result = get_number<Type>();
	}
	return result;
}

#endif
