#ifndef _FILE_OUTPUT_H_
#define _FILE_OUTPUT_H_

#include <string>

#include "board.h"
#include "life.h"

class FileOutput {
private:
	// ��������� �� ���� � ������ @filename
	// ���� ���� - �������� ����� �� ��������������
	// ���� ��� - ������ �� ������
	static void try_overwrite_file(std::string& filename);

	// ����������, ���������� �� ���� � ������/����� @filename
	static bool is_file_exist(const std::string& filename);

	// ���������� � ������ ���� ������� ������
	static void write_input_data_to_file(std::ofstream& fout, const Board& board);

	// �����, ������� ��������� ������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] static bool save_input_data_to_file(const Board& board);

	// �����, ������� ��������� �������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] static bool save_output_data_to_file(Simulator simulator);

	// ���������� � ������ ���� �������� ������
	static void write_output_data_to_file(std::ofstream& fout, Simulator simulator);


public:
	// ����� ����������� ��������� ���������� ������� ������ � ����
	static void save_input_data(const Board &board);

	// ����� ����������� ��������� ���������� �������� ������ � ����
	static bool save_output_data(const Simulator& simulator);
};

#endif