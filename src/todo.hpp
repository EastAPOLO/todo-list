#pragma once
#include <fstream>

class Todo {
public:
    Todo(std::string&);
    int get_last_priority();
    void add_tasks();
    void list_tasks();

private:
    int priority{0};
    std::string todo{""};
    std::string label{""};  // Assumption is made that @label is optional
    std::string buffer{""};
    std::ofstream output;
    std::ifstream input;
};
