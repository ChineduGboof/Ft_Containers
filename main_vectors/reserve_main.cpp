#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"




/************MAIN TO CHECK THE RESERVE FUNCTION *******************/

int main() {
    std::vector<int> numbers;
    
    // Print the initial capacity and size of the vector
    std::cout << "Initial Capacity: " << numbers.capacity() << std::endl;
    std::cout << "Initial Size: " << numbers.size() << std::endl;
    
    // Reserve capacity for 10 elements
    numbers.reserve(10);
    
    // Print the updated capacity and size of the vector
    std::cout << "Updated Capacity: " << numbers.capacity() << std::endl;
    std::cout << "Updated Size: " << numbers.size() << std::endl;
    
    return 0;
}

