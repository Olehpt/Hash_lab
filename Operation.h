#pragma once
#include <string>

enum class OperationType {
	ADD,
	DELETE,
	FIND
};

class Operation {
	OperationType type;
	std::string value;
public:
	Operation(OperationType t, std::string v) : type(t), value(v) {}
};

bool generateRandomOperations(size_t num, std::string filepath);