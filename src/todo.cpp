#include <iostream>
#include <sstream>
#include "todo.hpp"

Todo::Todo(std::string& path) : output(path, std::ios::app), input(path) {}

int Todo::get_last_priority() {
    buffer = read_stream();

    if (buffer == "") {
        return Todo::priority;
    }

    std::size_t newline = buffer.find_last_of('\n');
    std::string last_line = buffer.substr(newline + 1);

    std::istringstream in(last_line);
    in >> buffer;

    for(char& c : buffer){
        if(!isdigit(c)){
            c = ' ';
        }
    }

    priority = std::stoi(buffer);

    return priority;
}

std::string Todo::read_stream(){
    std::string temp = "";
    while(std::getline(input, buffer)){
        if(buffer != ""){
            temp += buffer + '\n';
        }
    }
    if(temp[temp.size() - 1 == '\n']){
        temp[temp.size() - 1] = ' ';
    }
    return temp;
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
    buffer = read_stream();
    std::cout << buffer << '\n';
}
