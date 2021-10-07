#include "descriptive_statistics.h"
#include "sort.h"
#include <iostream>

using namespace std;

long double median(int * arr, int size) {
	quickSort(arr, 0, size);
	return arr[(size - 1) / 2];
}
