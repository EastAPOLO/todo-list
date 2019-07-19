#include <sstream>
#include <iostream>
#include <cctype>
#include "todo.hpp"

int Todo::get_last_priority(std::ifstream& input){
    std::string line;
    std::string temp;

    while(std::getline(input, line)){
        std::istringstream in(line);
        in >> temp;
    }

    if(temp == ""){
        return 0;
    }

    if(!isdigit(temp[0]) && !isdigit(temp[temp.size() - 1])){
        temp[0] = ' ';
        temp[temp.size() - 1] = ' ';
    }else{
        return priority;
    }

    priority = std::stoi(temp);
 
    return priority;
}

void Todo::add_tasks(std::ofstream& output, std::ifstream& input){
    priority = get_last_priority(input) + 1;
    while(std::getline(std::cin, buffer)){
        std::istringstream in(buffer);
        output << '[' << priority << ']' << " " << buffer << std::endl;
        ++priority;
    }
}
