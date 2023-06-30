#include "header.h"
#include "algorithm.h"
#include "interface.h"


int main()
{
    //TODO: Добавить комментарии

    string in_file = "input.txt";
    string out_file = "output.txt";

    setlocale(LC_ALL, "Russian");

    print_message("Программа сортировки вставками (insertion sort)");
    auto size = request_number("Введите размер массива");

    generate_array_to_file(in_file, size);

    auto array = read_array(in_file);

    //TODO: Засечь время начала
    int begin_time = 0;

    auto sorted_array = sort(array);

    //TODO: Засечь время окончания
    int end_time = 0;

    //TODO: Сделать проверку
    auto success_sorted = test_sorted(sorted_array);

    write_array(out_file, sorted_array);

    //TODO: Вывести правильность отсортированного массива
    //TODO: Вывести время работы алгоритма
}