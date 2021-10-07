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
	dictionary * mode_value = new dictionary[size];
	dictionary current = dictionary(arr[0], 1);

	int move = 0, max_occurent = 0;

	for (int i = 1; i < size; ++i) {
		if (arr[i] == current.value) {
			current.occurent++;
		}
		else {
			current.value = arr[i];
			current.occurent = 1;
		}

		if (max_occurent < current.occurent) {
			mode_value->value = current.value;
			mode_value->occurent = current.occurent;
			max_occurent = current.occurent;
		}
		else if (max_occurent == current.occurent) {
			mode_value++;
			move++;
			(mode_value + move)->value = current.value;
			(mode_value + move)->occurent = current.occurent;
		}
	}
	for (int i = 0; i < size; ++i) {
		if (mode_value[i].occurent == max_occurent) {
			cout << mode_value[i].value << " ";
		}
		else {
			break;
		}
	}
	mode_value -= move;
	delete[] mode_value;
}