#include "descriptive_statistics.h"
#include <iostream>
#include "sort.h"

using namespace std;

struct dictionary
{
	int value;
	int occurent;

	dictionary() {
		value = 0;
		occurent = 0;
	}

	dictionary(int value, int occurent) {
		this->value = value;
		this->occurent = occurent;
	}
};

void mode(int* arr, int size) {
	dictionary * mode_value;
	dictionary current = dictionary(arr[0], 1);

	//for (int i = 1; i < size; ++i) {
	//	if (arr[i] == current.value) {
	//		current.value++;
	//	}
	//	else {
	//		if (mode_value->occurent < current.occurent) {

	//		}
	//	}
	//}
}