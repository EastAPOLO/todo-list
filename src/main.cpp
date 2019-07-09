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

    while(std::getline(std::cin, t.buffer)){
        std::istringstream in(t.buffer);
        t.priority = count;
        output << '[' << t.priority << ']' << " " << t.buffer << std::endl;
        ++count;
    }

    return 0;
}
