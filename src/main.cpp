#include <iostream>
#include "todo.hpp"

constexpr char quit = 'q';
constexpr char add = 'a';
constexpr char list = 'l';

int main() {
    std::string rel_path = "../todo.txt";
    char mode_char; 

    while(std::cin >> mode_char){
        Todo t{rel_path};
        switch(mode_char){
        case add:
            t.add_tasks();
            break;
        case list:
            t.list_tasks();
            break;
        default:
            break;
        }
    }

    return 0;
}
