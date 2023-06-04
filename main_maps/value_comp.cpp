#include <iostream>
#include <map>

int main() {
    std::map<char, int> mymap;

    mymap['x'] = 1001;
    mymap['y'] = 2002;
    mymap['z'] = 3003;
    
    std::pair<char, int> firstElement = *mymap.begin();           // First element
    std::pair<char, int> lastElement = *mymap.rbegin();           // Last element

    bool isFirstElementLess = mymap.value_comp()(firstElement, lastElement);

    std::cout << "The value of the first element (" << firstElement.second << ") is ";

    if (isFirstElementLess) {
        std::cout << "less than the value of the last element (" << lastElement.second << ")." << std::endl;
    } else {
        std::cout << "not less than the value of the last element (" << lastElement.second << ")." << std::endl;
    }

    return 0;
}
