#include "header.h"
#include "interface.h"


void print_message(string message)
{
    cout << message << endl;
}

int request_number(string message)
{
    cout << message << endl;
    int number;
    cin >> number;
    return number;
}

void generate_array_to_file(string path, int size)
{
    srand(time(0));
    vector<int> array(size);
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 1000;
    }
    write_array(path, array);
}

vector<int> read_array(string path)
{
    vector<int> array;
    ifstream file(path);
    string str;
    file >> str;
    array = split_string(str, ';');
    file.close();
    return array;
}

vector<int> split_string(string str, char separator) {
    int startIndex = 0, endIndex = 0;
    vector<int> splited;
    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            if (endIndex - startIndex > 0)
            {
                string temp;
                temp.append(str, startIndex, endIndex - startIndex);
                splited.push_back(stoi(temp));
            }
            startIndex = endIndex + 1;
        }
    }
    return splited;
}

void write_array(string path, vector<int> array)
{
    ofstream file(path);
    for (int i : array)
        file << i << ';';
    file << endl;
    file.close();
}