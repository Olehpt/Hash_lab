#pragma once
#include <string>

enum class RowType {
	EMPTY,
	OCCUPIED,
	DELETED
};

struct Row {
	std::string value;
	RowType type;
	static const int MAX_STRING_LENGTH = 15;
	//
	Row() : value(""), type(RowType::EMPTY) {} 
	Row(std::string v, RowType t) : value(v), type(t) {}
	bool HasValue() const;
	bool CheckStringLimit();
};

bool generateRows(size_t num, std::string filepath);