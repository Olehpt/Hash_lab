#include "Operation.h"
#include <fstream>
#include <iostream>

bool generateRandomOperations(size_t num, std::string filepath) {
	srand(time(0));

	std::string operation_str[] = { "+", "-", "?" };

	std::fstream file(filepath, std::ios::out);
	if (!file) {
		std::cerr << "Error opening file: " << filepath << std::endl;
		return 0;
	}

	for (size_t i = 0; i < num; i++) {
		size_t operation_type = rand() % 3;
		size_t string_length = rand() % 15 + 1;
		std::string str = "";
		for (size_t j = 0; j < string_length; j++) {
			char c = 'a' + rand() % 26;
			str += c;
		}
		file << operation_str[operation_type] << " " << str << std::endl;
	}

	return 1;
}