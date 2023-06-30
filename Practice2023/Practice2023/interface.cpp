#include <iostream>

#include "header.h"
#include "algo.h"
#include "interface.h"
using namespace std;


void hello(int value)
{
    ofstream fout("cppstudio.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    fout << "Работа с файлами в С++"; // запись строки в файл
    fout.close(); // закрываем файл

    vector<int> a = {1, 2, 3, 5, 4};
    cout << "Начальный массив\n";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "Отсортированный массив\n";
    vector<int> b = alg(a);
    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
}