#ifndef _MENU_H_
#define _MENU_H_

enum MENU {
	EXIT,
	CONSOLE,
	FILES,
	RANDOM,
	TEST
};

// ����������� ������������
void greetings();

// ������ ����� ����
void print_menu();

void print_menu_mode();

// �� ������ ������ ����������� ������ ���� ���������
void interface_menu();

#endif
