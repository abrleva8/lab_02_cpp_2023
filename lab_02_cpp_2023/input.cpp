#include "input.h"

bool Input::get_is_file_input() const {
	return this->is_file_input_;
}

bool Input::check_string(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '*' || str[i] != '-') {
			return false;
		}
	}
	return true;
}
