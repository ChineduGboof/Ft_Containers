// map::equal_range
#include <iostream>
#include <map>

/**

@brief Demonstrates the usage of the equal_range function in a map.
The equal_range function returns a pair of iterators representing the range of elements
in the map that have the same key as the one specified.
The first iterator points to the lower bound of the range (first element with a key not less than the specified key),
and the second iterator points to the upper bound of the range (first element with a key greater than the specified key).
*/

int main ()
{
  std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  {
    std::cout << "Passing Key 'b: " << std::endl;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
  }

  {
    std::cout << "Passing Key 'c: " << std::endl;
    ret = mymap.equal_range('c');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';

  }

  {
    std::cout << "Passing Key 'a: " << std::endl;
    ret = mymap.equal_range('a');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
  }

  return 0;
}