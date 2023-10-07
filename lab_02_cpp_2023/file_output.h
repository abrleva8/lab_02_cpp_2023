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
	void try_overwrite_file(std::string& filename) const;

	// ����������, ���������� �� ���� � ������/����� @filename
	static bool is_file_exist(const std::string& filename);

	// ���������� � ������ ���� ������� ������
	static void write_input_data_to_file(std::ofstream& fout, Board board);

	// �����, ������� ��������� ������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] bool save_input_data_to_file(Board board) const;

	// �����, ������� ��������� �������� ������ � ����
	// ���� ���-�� �� ���������� ���������� @false
	[[nodiscard]] bool save_output_data_to_file(Simulator board) const;

	// ���������� � ������ ���� �������� ������
	static void write_output_data_to_file(std::ofstream& fout, Simulator board);


public:
	// ����� ����������� ��������� ���������� ������� ������ � ����
	void save_input_data(const Board &board) const;

	// ����� ����������� ��������� ���������� �������� ������ � ����
	bool save_output_data(const Simulator& board) const;
};

#endif