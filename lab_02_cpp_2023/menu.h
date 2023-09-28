#ifndef _MENU_H_
#define _MENU_H_

enum MENU {
	EXIT,
	CONSOLE,
	FILES,
	RANDOM,
	TEST
};

// Приветствие пользователя
void greetings();

// Печает пунты меню
void print_menu();

void print_menu_mode();

// На данный момент реализована логика меню программы
void interface_menu();

#endif
