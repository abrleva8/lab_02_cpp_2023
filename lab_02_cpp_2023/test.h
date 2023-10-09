#ifndef _TEST_H_
#define _TEST_H_

#define NUMBER_OF_TESTS 5

#include "board.h"

class Test {
private:
	//В этом поле хранится успешно ли прошло тестирование
	bool is_success_;

	//В этом поле хранятся данные для теста
	Board data_[NUMBER_OF_TESTS];

	//В этом поле хранятся ответы на тесты
	Board answers_[NUMBER_OF_TESTS];

	//Метод запускает анализ текста для  @data_ и сверяет с @answers_
	// Возвращает тест с номером ошибки
	// Если ошибки  нет, то -1
	int check_in();

public:
	// Метод возвращает результат, который хранится в поле is_success_
	[[nodiscard]] bool get_is_success() const;

	// Конструктор для инициализации полей
	Test();
};

#endif