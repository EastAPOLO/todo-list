#pragma once
#include <fstream>

class Todo {
public:
    int get_last_priority(std::ifstream&);
    void add_tasks(std::ofstream&, std::ifstream&);

private:
    unsigned int priority{1};
    std::string todo{""};
    std::string label{""};  // Assumption is made that @label is optional
    std::string buffer{""};
};
