#include <iostream>
#include <string>
#include <deque>
#include <vector>
// #include "containers/vector.hpp"



/************MAIN TO CHECK THE USE OF ENABLE IFS *******************/
#include <iterator>
#include <type_traits>

template <class Iterator>
typename std::enable_if<!std::is_integral<Iterator>::value>::type
print_range(Iterator first, Iterator last) {
    std::cout << "Is Not Integral: ";
    for (Iterator it = first; it != last; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Case 1: Using print_range with vector iterators
    std::cout << "Printing vector elements: ";
    print_range(vec.begin(), vec.end());

    // Case 2: Using print_range with integral iterators
    int arr[] = {6, 7, 8, 9, 10};
    std::cout << "Printing array elements: ";
    print_range(arr, arr + 5); // Will result in a compilation error
    
    return 0;
}
