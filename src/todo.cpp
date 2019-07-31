#include "todo.hpp"
#include <iostream>
#include <sstream>

int Todo::get_last_priority(std::ifstream& input) {
    std::string line;
    std::string temp;

    while (std::getline(input, line)) {
        std::istringstream in(line);
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

void Todo::add_tasks(std::ofstream& output, std::ifstream& input) {
    priority = get_last_priority(input);

    /* If file has a priority greater than 1, increment to avoid a duplicate. */
    if (priority > 1) {
        priority++;
    }
    while (std::getline(std::cin, buffer)) {
        std::size_t label_pos = buffer.find("@");
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
