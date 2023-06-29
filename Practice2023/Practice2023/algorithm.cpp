#include "header.h"
using namespace std;

vector<int> alg(vector<int> a)
{
    int temp = 0;
    temp = a[4];
    a[4] = a[3];
    a[3] = temp;
    return a;
}