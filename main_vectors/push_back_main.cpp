#include <iostream>
#include <vector>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"

int main() {
    std::vector<int> vec;

    // Case where reserving more than required capacity is necessary
    vec.reserve(4);  // Reserve initial capacity of 4
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    for (int i = 0; i < 7; i++) {
        vec.push_back(i);
        std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;
    }

    std::cout << std::endl;

    // Case where reserving just one is sufficient
    vec.clear();  // Clear the vector
    vec.reserve(1);  // Reserve initial capacity of 1
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
        std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;
    }

    return 0;
}
