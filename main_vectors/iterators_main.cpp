#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"

/************MAIN TO CHECK THE ITERATORS *******************/

// #include "tools/iterator_traits.hpp"

// template <typename T>
// void testIteratorTraits() 
// {
// 	std::cout << typeid(typename ft::iterator_traits<T>::value_type).name() << std::endl;
// 	std::cout << typeid(typename ft::iterator_traits<T>::difference_type).name() << std::endl;
// 	std::cout << typeid(typename ft::iterator_traits<T>::pointer).name() << std::endl;
// 	std::cout << typeid(typename ft::iterator_traits<T>::reference).name() << std::endl;
// 	std::cout << typeid(typename ft::iterator_traits<T>::iterator_category).name() << std::endl;
// }


// int main() {
//     // Test iterator traits for different iterator types

//     typedef std::vector<int>::iterator VectorIterator;
//     std::cout << "Testing std::vector iterator traits:" << std::endl;
//     testIteratorTraits<VectorIterator>();

//     return 0;
// }



// #include <iostream>
// #include "tools/vector_iterator.hpp"
// // implement the begin | end | push 

// int main() {
//     // Create a vector
//     std::vector<int> vec = {1, 2, 3, 4, 5};

//     // Create vector iterators
//     ft::vector_iterator<std::vector<int>::iterator> it1 = vec.begin();
//     ft::vector_iterator<std::vector<int>::iterator> it2 = vec.end();

//     // Testing dereference operator (*)
//     while (it1 != it2) {
//         std::cout << *it1 << " ";
//         ++it1;
//     }
//     std::cout << std::endl;

//     // Test dereference operator (*)
//     std::cout << "Dereference operator: " << *it1 << std::endl;

//     // Test arrow operator (->)
//     std::cout << "Arrow operator: " << it1->size() << std::endl;

//     // Test subscript operator (it[n])
//     std::cout << "Subscript operator: " << it1[2] << std::endl;

//     // Test addition operator (it + n)
//     ft::vector_iterator<std::vector<int>::iterator> it3 = it1 + 2;
//     std::cout << "Addition operator: " << *it3 << std::endl;

//     // Test subtraction operator (it - n)
//     ft::vector_iterator<std::vector<int>::iterator> it4 = it2 - 2;
//     std::cout << "Subtraction operator: " << *it4 << std::endl;

//     // Test pre-increment operator (++it)
//     ++it1;
//     std::cout << "Pre-increment operator: " << *it1 << std::endl;

//     // Test post-increment operator (it++)
//     it1++;
//     std::cout << "Post-increment operator: " << *it1 << std::endl;

//     // Test pre-decrement operator (--it)
//     --it1;
//     std::cout << "Pre-decrement operator: " << *it1 << std::endl;

//     // Test post-decrement operator (it--)
//     it1--;
//     std::cout << "Post-decrement operator: " << *it1 << std::endl;

//     // Test addition assignment operator (it += n)
//     it1 += 2;
//     std::cout << "Addition assignment operator: " << *it1 << std::endl;

//     // Test subtraction assignment operator (it -= n)
//     it1 -= 2;
//     std::cout << "Subtraction assignment operator: " << *it1 << std::endl;

//     // Test equality operator (it == it)
//     bool isEqual = (it1 == it2);
//     std::cout << "Equality operator: " << isEqual << std::endl;

//     // Test inequality operator (it != it)
//     bool isNotEqual = (it1 != it2);
//     std::cout << "Inequality operator: " << isNotEqual << std::endl;

//     // Test less than operator (it < it)
//     bool isLessThan = (it1 < it2);
//     std::cout << "Less than operator: " << isLessThan << std::endl;

//     // Test greater than operator (it > it)
//     bool isGreaterThan = (it1 > it2);
//     std::cout << "Greater than operator: " << isGreaterThan << std::endl;

//     // Test less than or equal to operator (it <= it)
//     bool isLessThanOrEqual = (it1 <= it2);
//     std::cout << "Less than or equal to operator: " << isLessThanOrEqual << std::endl;

//     // Test greater than or equal to operator (it >= it)
//     bool isGreaterThanOrEqual = (it1 >= it2);
//     std::cout << "Greater than or equal to operator: " << isGreaterThanOrEqual << std::endl;

//     // Test subtraction operator (it - it)
//     ft::vector_iterator<std::vector<int>::iterator>::difference_type diff1 = it2 - it1;
//     std::cout << "Subtraction operator (it - it): " << diff1 << std::endl;

//     // Test subtraction operator (it - it)
//     ft::vector_iterator<std::vector<int>::iterator>::difference_type diff2 = it2 - it3;
//     std::cout << "Subtraction operator (it - it): " << diff2 << std::endl;

//     // Test addition operator (n + it)
//     ft::vector_iterator<std::vector<int>::iterator> it5 = 2 + it1;
//     std::cout << "Addition operator (n + it): " << *it5 << std::endl;

//     return 0;
// }
