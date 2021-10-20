//Acknowledgement:
//	Covariance implementation based on: https://www.geeksforgeeks.org/program-find-covariance/
//	Pearson Correlation Coefficient implementation based on: https://www.geeksforgeeks.org/program-find-correlation-coefficient/
//	Linear Regression implementation based on: 

#include "inferential_statistics.h"
#include <math.h>
#include<iostream>

using namespace std;

// Function to find mean.
float CalculateMean(int arr[], int array_size)
{
	float sum = 0;

	for (int i = 0; i < array_size; i++) {
		sum = sum + arr[i];
	}

	return sum / array_size;
}

// Function to find covariance.
float CalculateCovariance(int* x_arr, int* y_arr, int array_size)
{
	float sum = 0;

	cout << "\nnumbers inside CalculateVariance(): " << endl;
	for (int i = 0; i < array_size; ++i) {
		cout << x_arr[i] << " " << y_arr[i] << endl; // Prints wrong numbers. The problem is probably in the way the pointers are passed.
		sum = sum + (x_arr[i] - CalculateMean(x_arr, array_size)) * (y_arr[i] - CalculateMean(y_arr, array_size));
	}

	return sum / (array_size - 1);
}

//long double CalculatePearson(int x[], int y[], int arr_size)
//{
//
//	int sum_X = 0, sum_Y = 0, sum_XY = 0;
//	int squareSum_X = 0, squareSum_Y = 0;
//
//	for (int i = 0; i < arr_size; i++)
//	{
//		// sum of elements of array X.
//		sum_X = sum_X + x[i];
//
//		// sum of elements of array Y.
//		sum_Y = sum_Y + y[i];
//
//		// sum of X[i] * Y[i].
//		sum_XY = sum_XY + x[i] * y[i];
//
//		// sum of square of array elements.
//		squareSum_X = squareSum_X + x[i] * x[i];
//		squareSum_Y = squareSum_Y + y[i] * y[i];
//	}
//
//	// use formula for calculating correlation coefficient.
//	long double pearson = (long double)(arr_size * sum_XY - sum_X * sum_Y) / sqrt((arr_size * squareSum_X - sum_X * sum_X) * (arr_size * squareSum_Y - sum_Y * sum_Y));
//
//	return pearson;
//}
//
//long double CalculateLinearRegression() {
//	return 0;
//}