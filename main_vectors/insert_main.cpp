#include <iostream>
#include <vector>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"

int main() {
    // std::vector<int> vec;

    // // Single element insert (1)
    // std::cout << "Single element insert (1):" << std::endl;
    // std::vector<int>::iterator it = vec.insert(vec.begin(), 5);
    // std::cout << "Inserted element: " << *it << std::endl;
    // std::cout << "Vector elements after insert: ";
    // for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
    //     std::cout << *iter << " ";
    // }
    // std::cout << std::endl;

    // // Fill insert (2)
    // std::cout << "Fill insert (2):" << std::endl;
    // // vec.insert(<start location>, <size>, <value>)
    // vec.insert(vec.begin() + 1, 3, 10);
    // std::cout << "Vector elements after insert: ";
    // for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
    //     std::cout << *iter << " ";
    // }
    // std::cout << std::endl;

    // // Range insert (3)
    // std::cout << "Range insert (3):" << std::endl;
    // int arr[] = {1, 2, 3};
    // // vec.insert(<start location>, <pointer to start of array>, <pointer to end of array>)
    // vec.insert(vec.end(), arr, arr + 3);
    // std::cout << "Vector elements after insert: ";
    // for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
    //     std::cout << *iter << " ";
    // }
    // std::cout << std::endl;


    std::vector<int> vec;

    // Range insert (3)
    int arr[] = {1, 2, 3, 4};
    vec.insert(vec.begin(), arr, arr + 4);

    std::vector<int>::iterator it_begin = vec.begin();
    std::vector<int>::iterator it_end = vec.end();
    while(it_begin != it_end){
        std::cout << *it_begin << " ";
        it_begin++;
    }
    std::cout << std::endl;

    // Fill insert (2)
    // vec.insert(<start location>, <size>, <value>)
    vec.insert(vec.end(), 4, 5);
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Single element insert (1)
    vec.insert(vec.end(), 6);
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
