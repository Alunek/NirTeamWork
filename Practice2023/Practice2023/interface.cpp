#include <iostream>

#include "header.h"
using namespace std;


void hello(int value)
{
    vector<int> a = {1, 2, 3, 5, 4};
    cout << "Начальный массив\n";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "Отсортированный массив\n";
    vector<int> b = alg(a);
    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
}