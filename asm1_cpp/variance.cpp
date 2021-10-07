#include "descriptive_statistics.h"
#include <iostream>
#include <math.h>

long avrValue(int* arr, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum / size;
}

// Calculate variance of an array
long variance(int* arr, int size) {
    long numerator = 0;
    long avr = avrValue(arr, size);
    for (int i = 0; i < size; i++) {
        numerator = numerator + pow((arr[i] - avr), 2);
    }
    return numerator / (size - 1);
}

// Calculate standard deviation of an array
long standardDev(long variance) {
    return sqrt(variance);
}

// calculate mean absolute of an array
long meanAbsDev(int* arr, int size) {
    double numerator = 0;
    double avr = avrValue(arr, size);
    for (int i = 0; i < size; i++) {
        numerator = numerator + abs(arr[i] - avr);
    }
    return numerator / (int)size;
}

// Find the first quartile of the array
long firstQuartile(int* sorted_arr, int size) {
    if (size / 2 % 2 != 0)
        return sorted_arr[size / 4];
    return (sorted_arr[(size - 1) / 4] + sorted_arr[size / 4]) / 2;
}