// map::begin/end
#include <iostream>
#include <map>

int main()
{
    {
        std::cout << "Calling the begin function with three elements in the map" <<std::endl;
        std::map<char, int> myMap;

        myMap['c'] = 4;
        myMap['d'] = 5;
        myMap['e'] = 6;

        std::map<char, int>::iterator it;
        it = myMap.begin();

        // --it; // Decrement to get the iterator to the last element

        std::cout << "myMap.begin() => " << it->second << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "Calling the begin function with No Element in the map" <<std::endl;
        std::map<char, int> myMap;
        std::map<char, int>::iterator it;
        it = myMap.begin();

        std::cout << "myMap.begin() => " << it->second << std::endl;
        std::cout << std::endl;

    }

    {
        std::cout << "Calling the begin function with two elements with same key" <<std::endl;
        std::map<char, int> myMap;

        myMap['c'] = 10;
        myMap['c'] = 4;
        myMap['d'] = 5;
        myMap['e'] = 6;

        std::map<char, int>::iterator it;
        it = myMap.begin();

        std::cout << "myMap.begin() => " << it->second << std::endl;
        std::cout << std::endl;

    }

    {
        std::cout << "Calling the begin function with a bigger key(f) before a smaller key(c)" <<std::endl;
        std::map<char, int> myMap;

        myMap['f'] = 10;
        myMap['c'] = 4;
        myMap['d'] = 5;
        myMap['e'] = 6;

        std::map<char, int>::iterator it;
        it = myMap.begin();

        std::cout << "myMap.begin() => " << it->second << std::endl;
        std::cout << std::endl;

    }

    {
        std::cout << "Calling the end function with three elements in the map" <<std::endl;
        std::map<char, int> myMap;

        myMap['c'] = 4;
        myMap['d'] = 5;
        myMap['e'] = 6;

        std::map<char, int>::iterator it;
        it = myMap.end();

        std::cout << "myMap.end() => " << it->second << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
