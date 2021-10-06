#include <iostream>
#include <math.h>
#include "descriptive_statistics.h"
using namespace std;

long mean(int* ptr, int length)
{
    long answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += (*(ptr + i));
    }
    return answer / (length);

}

long variance_dev(int* ptr, int length)
{
    long answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += pow((float(*(ptr + i)) - mean(ptr, length)), 2);
    }
    return answer / float(length - 1);

}
long skewness(int* ptr, int length)
{
    long answer = 0;
    for (int i = 0; i < length; i++)
    {

        answer += pow((float(*(ptr + i)) - mean(ptr, length)) / sqrt(variance_dev(ptr, length)), 3);
    }
    return answer / length;
}


