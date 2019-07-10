#include <sstream>
#include <iostream>
#include "todo.hpp"

void add_tasks(std::ofstream& output, Todo& t, int& count){
    while(std::getline(std::cin, t.buffer)){
        std::istringstream in(t.buffer);
        t.priority = count;
        output << '[' << t.priority << ']' << " " << t.buffer << std::endl;
        ++count;
    }
}

int get_last_priority(std::ifstream& input){
    std::string line;
    std::string temp;
    int priority;

    while(std::getline(input, line)){
        std::istringstream in(line);
        in >> temp;
    }

    if(temp == ""){
        return 0;
    }

    for(int i = 0; i < temp.size(); ++i){
        if(temp[i] == '[' || temp[i] == ']'){
            temp[i] = ' ';
        }
    }

    priority = std::stoi(temp);
 
    return priority;
}

