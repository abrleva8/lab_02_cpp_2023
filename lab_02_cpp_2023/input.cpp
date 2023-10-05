#include "input.h"

bool Input::get_is_file_input() const {
	return this->is_file_input_;
}

bool Input::check_string(std::string str) {
	for (const char ch : str) {
		if (ch != '*' || ch != '_') {
			return false;
		}
	}
	return true;
}
