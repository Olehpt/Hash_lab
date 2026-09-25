#include "Hash.h"
#include "Row.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include "Operation.h"
#include "Palindrome.h"

HashTable::HashTable() {
	table = std::vector<Row>(TABLE_SIZE, Row("", RowType::EMPTY));
	size = 0;
}

HashTable::HashTable(const std::string& filepath) {
	table = std::vector<Row>(TABLE_SIZE, Row("", RowType::EMPTY));
	size = 0;
	std::ifstream file(filepath);
	if (!file) {
		std::cerr << "Error opening file: " << filepath << std::endl;
		return;
	}
	//
	auto start = std::chrono::high_resolution_clock::now();
	//
	std::string line;
	while (std::getline(file, line)) {
		add(line);
	}
	//
	auto end = std::chrono::high_resolution_clock::now();
	//
	double seconds = std::chrono::duration<double>(end - start).count();
	std::cout << "Hash table was created by: " << filepath << "\n";
	std::cout << "Time taken to create hash table: " << seconds << " seconds\n";
	info();
	file.close();
}

size_t HashFunc(const std::string& str) {
	size_t hash = 0;
	for (char c : str) {
		hash = (hash * HashTable::P + c) % HashTable::TABLE_SIZE;
	}
	return hash;
}

bool HashTable::find(const std::string& value, size_t &hash) {
	hash = HashFunc(value);
	Row r = table[hash];
	while (r.type != RowType::EMPTY) {
		if (r.type == RowType::OCCUPIED && r.value == value) {
			return 1;
		}
		hash = (hash + 1) % TABLE_SIZE;
		r = table[hash];
	}
	return 0;
}

bool HashTable::add(const std::string& value) {
	size_t hash = 0;
	if (find(value, hash)) return 1;
	hash = HashFunc(value);
	Row r = table[hash];
	while (r.type == RowType::OCCUPIED) {
		hash = (hash + 1) % TABLE_SIZE;
		r = table[hash];
	}
	table[hash] = Row(value, RowType::OCCUPIED);
	size++;
	return 1;
}

bool HashTable::remove(const std::string& value) {
	size_t hash = 0;
	if (!find(value, hash)) return 1;
	//hash = HashFunc(value);
	table[hash] = Row("", RowType::DELETED);
	size--;
	return 1;
}

void HashTable::info() {
	std::cout << "Hash table capacity: " << TABLE_SIZE << std::endl;
	std::cout << "Hash table acutal size: " << size << std::endl;
}

void HashTable::applyOperations(const std::string& filepath) {
	std::ifstream file(filepath);
	if (!file) {
		std::cerr << "Error opening file: " << filepath << std::endl;
		return;
	}
	std::string operation_type, str_value;
	while (file >> operation_type >> str_value) {
		if (operation_type == "+") {
			add(str_value);
		}
		else if (operation_type == "-") {
			remove(str_value);
		}
		else if (operation_type == "?") {
			size_t hash = 0;
			bool found = find(str_value, hash);
		}
	}
}

void HashTable::usePalindrome() {
	size_t counter = 0;
	//
	auto start = std::chrono::high_resolution_clock::now();
	//
	for (auto r : table) {
		if (r.type == RowType::OCCUPIED && palindrome(r.value)) {
			counter++;
		}
	}
	//
	auto end = std::chrono::high_resolution_clock::now();
	//
	double seconds = std::chrono::duration<double>(end - start).count();
	std::cout << "Found all palindromes in hash table: " << counter << "\n";
	std::cout << "Time taken: " << seconds << " seconds\n";
}