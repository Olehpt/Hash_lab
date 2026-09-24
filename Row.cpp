#include "Row.h"
#include <fstream>
#include <iostream>

bool Row::HasValue() const {
	return value.empty();
}

bool Row::CheckStringLimit() {
	bool res = value.length() <= MAX_STRING_LENGTH;
	if (!res) {
		value = value.substr(0, MAX_STRING_LENGTH);
	}
	return res;
}

bool generateRows(size_t num, std::string filepath) {
	srand(time(0));
	std::fstream file(filepath, std::ios::out);
	if (!file) {
		std::cerr << "Error opening file: " << filepath << std::endl;
		return 0;
	}
	for (size_t i = 0; i < num; i++) {
		size_t string_length = rand() % 15 + 1;
		std::string str = "";
		for (size_t j = 0; j < string_length; j++) {
			char c = 'a' + rand() % 26;
			str += c;
		}
		file << str << "\n";
	}
	return 1;
}