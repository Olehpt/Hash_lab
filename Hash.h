#pragma once
#include <string>
#include <vector>

#include "Row.h"

class Hash {
	std::vector<Row> table;
	int size;
	static const size_t TABLE_SIZE = 2*10e5;
	static const size_t P = 31;
public:
	Hash();
	Hash(const std::string& filepath);
	bool add(const std::string& value);
	bool remove(const std::string& value);
	bool find(const std::string& value, size_t& hash);
	friend size_t HashFunc(const std::string& str);
	void info();
	void applyOperations(const std::string& filepath);
};

size_t HashFunc(const std::string& str);