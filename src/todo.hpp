#pragma once
#include <fstream>

struct Todo {
    int priority;
    std::string todo;
    std::string label;
    std::string buffer;
};

void add_tasks(std::ofstream&, Todo&, int&);

int get_last_priority(std::ifstream&);
