#include "descriptive_statistics.h"
#include <iostream>
#include <math.h>

using namespace std;

long double mean1(int* ptr, int length)
{
    long double answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += *(ptr + i);
    }
    answer /= length;
    return answer;
}
long double variance1(int* ptr, int length)
{
    long double answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += pow(*(ptr + i) - mean1(ptr, length), 2);
    }
    answer = answer / ((float)length - 1.0f);
    return answer;
}

long double deviation1(int* ptr, int length)
{
    long double answer = sqrt(variance1( ptr,length));
    return answer ;
}

long double skewness(int* ptr, int length)
{
    long double answer = 0;
    for (int i = 0; i < length; i++)
    {

        answer += pow((*(ptr + i) - mean1(ptr, length)) / deviation1(ptr, length), 3);
    }
    return answer / length;
}
