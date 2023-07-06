#pragma once
#include "header.h"


void print_message(string message);
int request_number(string message);
void generate_array_to_file(string path, int size);
vector<int> read_array(string path);
void write_array(string path, vector<int> array);
vector<int> split_string(string str, char separator);