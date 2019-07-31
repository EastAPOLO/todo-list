#include "todo.hpp"

int main() {
    std::string rel_path = "../todo.txt";
    std::ofstream output(rel_path, std::ios::app);
    std::ifstream input(rel_path);
    Todo t;
    t.add_tasks(output, input);

    return 0;
}
