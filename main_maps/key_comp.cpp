#include <iostream>
#include <map>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
int main() {
    std::map<char, int> mymap;

    mymap['x'] = 1001;
    mymap['y'] = 2002;
    mymap['z'] = 3003;

    std::map<char, int>::iterator firstElement = mymap.begin();        // Iterator to the first element
    std::map<char, int>::reverse_iterator lastElement = mymap.rbegin(); // Reverse iterator to the last element

    bool isFirstKeyLess = mymap.key_comp()(firstElement->first, lastElement->first);

    std::cout << "The key of the first element ('" << firstElement->first << "') is ";

    if (isFirstKeyLess) {
        std::cout << "less than the key of the last element ('" << lastElement->first << "')." << std::endl;
    } else {
        std::cout << "not less than the key of the last element ('" << lastElement->first << "')." << std::endl;
    }

    return 0;
}
