#include <iostream>
#include <string>
#include <deque>
#include <vector>
// #include "containers/vector.hpp"


/************MAIN TO CHECK THE RESIZE FUNCTION *******************/

// int main() {
//     std::vector<int> numbers;
//     numbers.push_back(1);
//     numbers.push_back(2);
//     numbers.push_back(3);
//     numbers.push_back(4);
//     numbers.push_back(5);

//     std::cout << "Initial size: " << numbers.size() << std::endl;
//     std::cout << "Initial elements: ";
//     for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Case 1: Increase the size to 7 and initialize new elements with value 0
//     numbers.resize(7, 0);

//     std::cout << "Size after resize 1: " << numbers.size() << std::endl;
//     std::cout << "Elements after resize 1: ";
//     for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Case 2: Reduce the size to 3, removing excess elements
//     numbers.resize(3);

//     std::cout << "Size after resize 2: " << numbers.size() << std::endl;
//     std::cout << "Elements after resize 2: ";
//     for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
