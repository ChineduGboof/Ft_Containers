#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
# define NAMESPACE std
/************MAIN TO CHECK THE ASSIGN FUNCTION *******************/


int main() {
    std::vector<int> numbers;

    // Assign using the range version
    int rangeValues[] = {1, 2, 3, 4, 5};
    size_t rangeSize = sizeof(rangeValues) / sizeof(rangeValues[0]);
    // assign values from the first (rangeValues)to the last value(rangeValues + rangeSize)
    numbers.assign(rangeValues, rangeValues + rangeSize);
    std::cout << "range size: " << rangeSize << std::endl;
    std::cout << "After assign (range): ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Assign using the fill version
    int fillValue = 9;
    size_t fillSize = 7;
    // fills an array of 7 values with 9
    numbers.assign(fillSize, fillValue);

    std::cout << "After assign (fill): ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
