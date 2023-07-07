#include "header.h"
#include "algorithm.h"
#include "interface.h"


int main()
{
    setlocale(LC_ALL, "ru-RU");
    auto choice = request_number("����� ������ ���������:\n0 - �������� ������ �� ��������� ������� � �������� ��������\n1 - ����� � ������ ���������");
    if (!choice) {
        while (true)
        {

            string in_file = "input.txt";
            string out_file = "output.txt";

            print_message("��������� ���������� ��������� (insertion sort)");

            auto size = request_number("������� ������ �������:");

            generate_array_to_file(in_file, size);

            auto array = read_array(in_file);

            auto begin_time = chrono::steady_clock::now(); // ������ ����� ������
            sort(array);
            auto end_time = chrono::steady_clock::now(); // ������ ����� ���������
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            auto success_sorted = test_sorted(array); // ������ �������� �� ��������� ����������

            write_array(out_file, array);

            print_message(success_sorted ? "������ ������������ ���������" : "������ ������������ �� ���������");
            print_message("����� ������ ���������: " + to_string(time) + "���.");
            print_message("");
        }
    }
    else
    {
        auto size = 10;
        vector<int> sorted_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        vector<int> reversed_array = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        vector<int> random_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        srand(time(0));
        for (int i = 0; i < size; ++i)
        {
            random_array[i] = rand() % 100;
        }

        // ��������������� ������
        {
            print_message("��������������� ������ �� ����������: ");
            for (int i : sorted_array)
                cout << i << ' ';
            cout << endl;

            auto begin_time = chrono::steady_clock::now(); // ������ ����� ������
            sort(sorted_array);
            auto end_time = chrono::steady_clock::now(); // ������ ����� ���������
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            print_message("��������������� ������ ����� ����������: ");
            for (int i : sorted_array)
                cout << i << ' ';
            cout << endl;

            print_message("����� ������ ��������� �� ��������������� �������: " + to_string(time) + "���.");
            print_message("");
        }

        // ��������������� ������
        {
            print_message("��������������� ������ �� ����������: ");
            for (int i : reversed_array)
                cout << i << ' ';
            cout << endl;

            auto begin_time = chrono::steady_clock::now(); // ������ ����� ������
            sort(reversed_array);
            auto end_time = chrono::steady_clock::now(); // ������ ����� ���������
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            print_message("��������������� ������ ����� ����������: ");
            for (int i : reversed_array)
                cout << i << ' ';
            cout << endl;

            print_message("����� ������ ��������� �� ��������������� �������: " + to_string(time) + "���.");
            print_message("");
        }

        // ��������� ������
        {

            print_message("��������� ������ �� ����������: ");
            for (int i : random_array)
                cout << i << ' ';
            cout << endl;

            auto begin_time = chrono::steady_clock::now(); // ������ ����� ������
            sort(random_array);
            auto end_time = chrono::steady_clock::now(); // ������ ����� ���������
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            print_message("��������� ������ ����� ����������: ");
            for (int i : random_array)
                cout << i << ' ';
            cout << endl;

            print_message("����� ������ ��������� �� ��������� �������: " + to_string(time) + "���.");
            print_message("");
        }
    }
}