#include "descriptive_statistics.h"
#include <iostream>
#include <math.h>

using namespace std;

long double mean(int* ptr, int length)
{
    long double answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += *(ptr + i);
    }
    answer /= length;
    return answer;
}
long double variance(int* ptr, int length)
{
    long double answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += pow(*(ptr + i) - mean(ptr, length), 2);
    }
    answer = answer / ((float)length - 1.0f);
    return answer;
}

long double deviation(int* ptr, int length)
{
    long double answer = sqrt(variance( ptr,length));
    return answer ;
}

long double skewness(int* ptr, int length)
{
    long double answer = 0;
    for (int i = 0; i < length; i++)
    {

        answer += pow((*(ptr + i) - mean(ptr, length)) / deviation(ptr, length), 3);
    }
    return answer / length;
}

long double kurtosis(int* ptr, int length)
{
    long double answer = 0;

    for (int i = 0; i < length; i++)
    {
        answer += pow((*(ptr + i) - mean(ptr, length)) /deviation(ptr, length), 4);
    }
    answer = (answer / length) - 3;
    return answer;
}