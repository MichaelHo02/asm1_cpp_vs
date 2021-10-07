#include "descriptive_statistics.h"
#include "sort.h"
#include <iostream>

using namespace std;

long median(int * arr, int size) {
	quickSort(arr, 0, size - 1);
	cout << "This is the index: " << (size - 1) / 2 << " " << endl;
	return arr[(size - 1) / 2];
}
