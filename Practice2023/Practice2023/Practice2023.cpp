#include "header.h"
#include "algorithm.h"
#include "interface.h"


int main()
{
    while (true)
    {
        setlocale(LC_ALL, "ru-RU");

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