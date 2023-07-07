#include "header.h"
#include "algorithm.h"
#include "interface.h"


int main()
{
    setlocale(LC_ALL, "ru-RU");
    auto choice = request_number("Режим работы программы:\n0 - Проверка работы на случайном массиве с заданным размером\n1 - Отчет о работе алгоритма");
    if (!choice) {
        while (true)
        {

            string in_file = "input.txt";
            string out_file = "output.txt";

            print_message("Программа сортировки вставками (insertion sort)");

            auto size = request_number("Введите размер массива:");

            generate_array_to_file(in_file, size);

            auto array = read_array(in_file);

            auto begin_time = chrono::steady_clock::now(); // Засечь время начала
            sort(array);
            auto end_time = chrono::steady_clock::now(); // Засечь время окончания
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            auto success_sorted = test_sorted(array); // Делаем проверку на правильно сортировки

            write_array(out_file, array);

            print_message(success_sorted ? "Массив отсортирован правильно" : "Массив отсортирован не правильно");
            print_message("Время работы алгоритма: " + to_string(time) + "сек.");
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

        // Отсортированный массив
        {
            print_message("Отсортированный массив до сортировки: ");
            for (int i : sorted_array)
                cout << i << ' ';
            cout << endl;

            auto begin_time = chrono::steady_clock::now(); // Засечь время начала
            sort(sorted_array);
            auto end_time = chrono::steady_clock::now(); // Засечь время окончания
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            print_message("Отсортированный массив после сортировки: ");
            for (int i : sorted_array)
                cout << i << ' ';
            cout << endl;

            print_message("Время работы алгоритма на отсортированном массиве: " + to_string(time) + "сек.");
            print_message("");
        }

        // Инвертированный массив
        {
            print_message("Инвертированный массив до сортировки: ");
            for (int i : reversed_array)
                cout << i << ' ';
            cout << endl;

            auto begin_time = chrono::steady_clock::now(); // Засечь время начала
            sort(reversed_array);
            auto end_time = chrono::steady_clock::now(); // Засечь время окончания
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            print_message("Инвертированный массив после сортировки: ");
            for (int i : reversed_array)
                cout << i << ' ';
            cout << endl;

            print_message("Время работы алгоритма на инвертированном массиве: " + to_string(time) + "сек.");
            print_message("");
        }

        // Случайный массив
        {

            print_message("Случайный массив до сортировки: ");
            for (int i : random_array)
                cout << i << ' ';
            cout << endl;

            auto begin_time = chrono::steady_clock::now(); // Засечь время начала
            sort(random_array);
            auto end_time = chrono::steady_clock::now(); // Засечь время окончания
            double time = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time).count() / 1000000000.0;

            print_message("Случайный массив после сортировки: ");
            for (int i : random_array)
                cout << i << ' ';
            cout << endl;

            print_message("Время работы алгоритма на случайном массиве: " + to_string(time) + "сек.");
            print_message("");
        }
    }
}