#include <cstdlib>
#include <iostream>

#include "menu.h"


int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	greetings();
	interface_menu();
	system("pause");
}