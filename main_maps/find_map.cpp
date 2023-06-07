// map::find
#include <iostream>
#include <map>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
int main ()
{
    std::map<char,int> mymap;
    std::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    // delete key b 
    it = mymap.find('b');
    //   if (it != mymap.end())
    mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
    std::cout << "check for deleted key b and key e which is not present" << std::endl;
    std::cout << "b => " << mymap.find('b')->second << '\n';
    std::cout << "b => " << mymap.find('e')->second << '\n';

  return 0;
}