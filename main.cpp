#include <iostream>
#include <string>
#include <deque>
#include <vector>
// #include "containers/vector.hpp"

// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }


/************MAIN TO CHECK THE CONSTRUCTORS *******************/

// int main()
// {
// 	//	Checking the default constructor
// 	std::vector<int> myInt;
// 	ft::vector<int> myInt2;

// 	std::cout << "default size: " << myInt.size() << std::endl;

// 	//	Checking the fill constructor
// 	std::vector<int> myIntFill(5, 4);
// 	ft::vector<int> myIntFill2(5, 4);
// 	std::cout << "fill size: " << myIntFill.size() << std::endl;

// 	// myIntFill2[1]
// 	// *myIntFill2 + 1

// 	std::vector<int>::const_iterator test = myIntFill.begin() + 3;
// 	std::cout << *test << std::endl;
// }


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


// /************MAIN TO CHECK THE RESERVE FUNCTION *******************/

// int main() {
//     std::vector<int> numbers;
    
//     // Print the initial capacity and size of the vector
//     std::cout << "Initial Capacity: " << numbers.capacity() << std::endl;
//     std::cout << "Initial Size: " << numbers.size() << std::endl;
    
//     // Reserve capacity for 10 elements
//     numbers.reserve(10);
    
//     // Print the updated capacity and size of the vector
//     std::cout << "Updated Capacity: " << numbers.capacity() << std::endl;
//     std::cout << "Updated Size: " << numbers.size() << std::endl;
    
//     return 0;
// }



/************MAIN TO CHECK THE RESIZE FUNCTION *******************/

// int main() {
//     std::vector<int> numbers;
//     numbers.push_back(1);
//     numbers.push_back(2);
//     numbers.push_back(3);
//     numbers.push_back(4);
//     numbers.push_back(5);

//     std::cout << "Initial size: " << numbers.size() << std::endl;
//     std::cout << "Initial elements: ";
//     for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Case 1: Increase the size to 7 and initialize new elements with value 0
//     numbers.resize(7, 0);

//     std::cout << "Size after resize 1: " << numbers.size() << std::endl;
//     std::cout << "Elements after resize 1: ";
//     for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Case 2: Reduce the size to 3, removing excess elements
//     numbers.resize(3);

//     std::cout << "Size after resize 2: " << numbers.size() << std::endl;
//     std::cout << "Elements after resize 2: ";
//     for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


/************MAIN TO CHECK THE ASSIGN FUNCTION *******************/


// int main() {
//     std::vector<int> numbers;

//     // Assign using the range version
//     int rangeValues[] = {1, 2, 3, 4, 5};
//     size_t rangeSize = sizeof(rangeValues) / sizeof(rangeValues[0]);
//     // assign values from the first (rangeValues)to the last value(rangeValues + rangeSize)
//     numbers.assign(rangeValues, rangeValues + rangeSize);
//     std::cout << "range size: " << rangeSize << std::endl;
//     std::cout << "After assign (range): ";
//     for (size_t i = 0; i < numbers.size(); ++i) {
//         std::cout << numbers[i] << " ";
//     }
//     std::cout << std::endl;

//     // Assign using the fill version
//     int fillValue = 9;
//     size_t fillSize = 7;
//     // fills an array of 7 values with 9
//     numbers.assign(fillSize, fillValue);

//     std::cout << "After assign (fill): ";
//     for (size_t i = 0; i < numbers.size(); ++i) {
//         std::cout << numbers[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


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

