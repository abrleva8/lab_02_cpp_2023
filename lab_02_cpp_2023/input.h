#ifndef _INPUT_H_
#define _INPUT_H_

#include "board.h"

// Абстрактный класс реализующий чтение массива
class Input {
protected:
	bool is_file_input_ = false;
	const int MAX_SIZE = 20;
public:
	// Контракт метода:
	// 1 - Записать в поле @text - текст
	// 2 - Вернуть успешно или нет
	virtual bool read(Board& board) = 0;

	[[nodiscard]] bool get_is_file_input() const;

	static bool check_string(const std::string& str);

	// Виртуальный деструктор
	virtual ~Input() = default;
};

#endif