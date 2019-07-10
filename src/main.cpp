#include <iostream>
#include <sstream>
#include "todo.hpp"

int main(){ 
    std::string rel_path = "../todo.txt";
    std::ofstream output(rel_path, std::ios::app);
    std::ifstream input(rel_path);
    Todo t;
    int count = 1;
    int last_priority = get_last_priority(input);

    if(last_priority >= count){
        count = last_priority + 1;
    }

    add_tasks(output, t, count);

    return 0;
}
