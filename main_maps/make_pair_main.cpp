#include <iostream>
#include <vector>
#include <map>

int main() {
            
    std::pair<std::string, int>worth;
    worth = std::make_pair("Bugsy", 400);
    std::cout << "Worth of " << worth.first << " " << worth.second << std::endl;

    return 0;
}
