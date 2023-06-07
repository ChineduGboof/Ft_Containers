// map::insert (C++98)
#include <iostream>
#include <map>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
int main ()
{
    std::map<char, int>mymap;
    {
        std::cout << "Single Element Insertion: " << std::endl;
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::map<char, int>::iterator it;
        for (it = mymap.begin(); it != mymap.end(); ++it){
            std::cout << it->second << std::endl;
        }
        std::pair<std::map<char, int>::iterator, bool> res;
        res = mymap.insert(std::pair<char, int>('a', 70));
        if (res.second == false){
            std::cout << "Element '" << res.first->first << "' already exists with value " << res.first->second << std::endl;
        }
    }
        std::cout << "Insertion with Hint: " << std::endl;
        // second insert function version (with hint position):
        std::map<char,int>::iterator it = mymap.begin();
    {
        mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
        for (it = mymap.begin(); it != mymap.end(); ++it){
            std::cout << it->second << std::endl;
        }

    }

    {

        // third insert function version (range insertion):
        // start at beginning and end when you find c
        std::cout << "Range Insertion: " << std::endl;
        std::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

  return 0;
}