#include <iostream>

#include "header.h"
#include "algo.h"
#include "interface.h"
using namespace std;


void hello(int value)
{
    ofstream fout("cppstudio.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ cppstudio.txt
    fout << "������ � ������� � �++"; // ������ ������ � ����
    fout.close(); // ��������� ����

    vector<int> a = {1, 2, 3, 5, 4};
    cout << "��������� ������\n";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "��������������� ������\n";
    vector<int> b = alg(a);
    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
}