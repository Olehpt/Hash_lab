#include <iostream>

#include "Row.h"
#include "Operation.h"
#include "Hash.h"

int main()
{
	//generateRandomOperations(100, "_operations.txt");
	//generateRows(1000000, "_rows.txt");
	Hash hash_table("_rows.txt");
	hash_table.applyOperations("_operations.txt");
	hash_table.info();
}
