#include "header.h"
#include "algorithm.h"


void sort(vector<int>& array)
{
    for (int i = 1; i < array.size(); ++i)
    {
        int cur = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > cur)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = cur;
    }
}

bool test_sorted(vector<int>& array)
{
    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] < array[i - 1])
            return false;
    }
    return true;
}