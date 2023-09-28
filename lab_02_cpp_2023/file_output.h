#ifndef _FILE_OUTPUT_H_
#define _FILE_OUTPUT_H_

#include <string>
#include "board.h"

class FileOutput {
private:
	// Проверяет ли файл с именем @filename
	// Если есть - уточняет стоит ли перезаписывать
	// Если нет - ничего не делает
	void try_overwrite_file(std::string& filename) const;

	// Возвращает, существует ли файл с именем/путем @filename
	static bool is_file_exist(const std::string& filename);

	// Записывает в данный файл входные данные
	static void write_input_data_to_file(std::ofstream& fout, Board board);

	// Метод, который сохраняет входные данные в файл
	// Если что-то не получилось возвращает @false
	[[nodiscard]] bool save_input_data_to_file(Board board) const;


public:
	// Метод запускающий процедуру сохранения входных данных в файл
	void save_input_data(const Board &board) const;
};

#endif