#include <iostream>
#include <sstream>
#include "todo.hpp"

Todo::Todo(std::string& path) : output(path, std::ios::app), input(path) {}

int Todo::get_last_priority() {
    std::string temp;

    while (std::getline(input, buffer)) {
        std::istringstream in(buffer);
        in >> temp;
    }

    if (temp == "") {
        return Todo::priority;
    }

    for(char& c : temp){
        if(!isdigit(c)){
            c = ' ';
        }
    }

    priority = std::stoi(temp);

    return priority;
}

void Todo::add_tasks() {
    priority = get_last_priority() + 1;

    while (std::getline(std::cin >> std::ws, buffer)) {
        std::size_t label_pos = buffer.find('@');
        if (std::string::npos != label_pos) {
            todo = buffer.substr(0, label_pos - 1);
            label = buffer.substr(label_pos);
            output << '[' << priority << ']' << " " << todo << " " << label
                   << std::endl;
        } else {
            todo = buffer.substr(0);
            output << '[' << priority << ']' << " " << todo << std::endl;
        }
        ++priority;
    }
}

void Todo::list_tasks(){
    while(std::getline(input, buffer)){
        std::cout << buffer << '\n';
    }
}
