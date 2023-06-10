/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:32 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 01:54:52 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename T>
void printVectorComparison(const std::vector<T>& stdVec, const ft::vector<T>& ftVec) {
    typename std::vector<T>::const_iterator stdIt = stdVec.begin();
    typename ft::vector<T>::const_iterator ftIt = ftVec.begin();

    std::cout << GREEN << "std::vector: ";
    for (; stdIt != stdVec.end(); ++stdIt)
        std::cout << GREEN << *stdIt << " " << DEFAULT;

    std::cout << YELLOW << "\nft::vector:  ";
    for (; ftIt != ftVec.end(); ++ftIt)
        std::cout << YELLOW << *ftIt << " " << DEFAULT;

    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T>
void printVectorComparison(T std, T ft) {
    std::cout << GREEN << "std::vector: ";
    std::cout << GREEN << std << " " << DEFAULT;

    std::cout << YELLOW << "\nft::vector:  ";
    std::cout << YELLOW << ft << " " << DEFAULT;

    std::cout << std::endl;
    std::cout << std::endl;
}

void vector_tests() {
    {
        std::cout << "TESTING DEFAULT CONSTRUCTOR" << std::endl;
        std::vector<int> stdInt;
        ft::vector<int> ftInt;
        std::cout << "Print the Vector Size" << std::endl;
        printVectorComparison(stdInt.size(), ftInt.size());
    }

    {
        std::cout << "TESTING FILL CONSTRUCTOR" << std::endl;
        std::vector<int> stdIntFill(5, 4);
        ft::vector<int> ftIntFill(5, 4);
        printVectorComparison(stdIntFill, ftIntFill);
        std::cout << "Print the Vector Size" << std::endl;
        printVectorComparison(stdIntFill.size(), ftIntFill.size());
    }

    {
        std::cout << "TESTING INSERTION AT BEGINNING AND END" << std::endl;
        std::vector<int> stdIntInsert;
        ft::vector<int> ftIntInsert;

        stdIntInsert.insert(stdIntInsert.begin(), 42);  // Insert at the beginning
        ftIntInsert.insert(ftIntInsert.begin(), 42);

        stdIntInsert.push_back(200);  // Push at the end
        ftIntInsert.push_back(200);
        
        stdIntInsert.insert(stdIntInsert.end(), 99);  // Insert at the end
        ftIntInsert.insert(ftIntInsert.end(), 99);


        printVectorComparison(stdIntInsert, ftIntInsert);
    }

    {
        std::cout << "TESTING ERASING ELEMENTS" << std::endl;
        std::vector<int> stdInt(5);
        ft::vector<int> ftInt(5);

        stdInt.erase(stdInt.begin() + 2);  // Erase element at position 2
        ftInt.erase(ftInt.begin() + 2);

        stdInt.pop_back();  // Erase last element
        ftInt.pop_back();

        printVectorComparison(stdInt, ftInt);
    }

    {
        std::cout << "TESTING RESIZING THE VECTOR" << std::endl;
        std::vector<int> stdIntResize;
        ft::vector<int> ftIntResize;

        stdIntResize.resize(100000);  // Resize to a larger size
        ftIntResize.resize(100000);
        printVectorComparison(stdIntResize.size(), ftIntResize.size());

        stdIntResize.resize(3);  // Resize to a smaller size
        ftIntResize.resize(3);
        printVectorComparison(stdIntResize.size(), ftIntResize.size());

        stdIntResize.resize(5, 42);  // Resize and initialize new elements
        ftIntResize.resize(5, 42);

        printVectorComparison(stdIntResize, ftIntResize);
    }

    {
        std::cout << "TESTING ACCESSING ELEMENTS" << std::endl;
        std::vector<int> stdIntAccess;
        ft::vector<int> ftIntAccess;
        
        for (int i = 2; i < 7; i++){
            stdIntAccess.push_back(i);
            ftIntAccess.push_back(i);
        }
        for (std::vector<int>::iterator it = stdIntAccess.begin(); it != stdIntAccess.end(); it++){
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << GREEN << "std::vector element at position 2: " << stdIntAccess[2] << DEFAULT << std::endl;
        std::cout << YELLOW << "ft::vector element at position 2: " << ftIntAccess[2] << DEFAULT << std::endl;

        try {
            std::cout << GREEN << "std::vector element at position 10: " << stdIntAccess.at(10) << DEFAULT << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << GREEN << "std::vector exception: " << e.what() << DEFAULT << std::endl;
        }

        try {
            std::cout << YELLOW << "ft::vector element at position 10: " << ftIntAccess.at(10) << DEFAULT << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << YELLOW << "ft::vector exception: " << e.what() << DEFAULT << std::endl;
        }
    }

    {
        std::cout << "TESTING CAPACITY-RELATED FUNCTIONS" << std::endl;
        std::vector<int> stdIntCapacity;
        ft::vector<int> ftIntCapacity;

        std::cout << GREEN << "std::vector capacity: " << stdIntCapacity.capacity() << DEFAULT << std::endl;
        std::cout << YELLOW << "ft::vector capacity: " << ftIntCapacity.capacity() << DEFAULT << std::endl;

        stdIntCapacity.reserve(10);
        ftIntCapacity.reserve(10);

        std::cout << GREEN <<  "std::vector capacity after reserve: " << stdIntCapacity.capacity() << DEFAULT << std::endl;
        std::cout << YELLOW << "ft::vector capacity after reserve: " << ftIntCapacity.capacity() << DEFAULT << std::endl;

        stdIntCapacity.reserve(100);
        ftIntCapacity.reserve(100);

        std::cout << GREEN <<  "std::vector capacity after reserve: " << stdIntCapacity.capacity() << DEFAULT << std::endl;
        std::cout << YELLOW << "ft::vector capacity after reserve: " << ftIntCapacity.capacity() << DEFAULT << std::endl;
    }

    {
        std::cout << "TESTING EDGE CASES WITH ITERATORS" << std::endl;
        std::vector<int> stdIntIterator(5, 100);
        ft::vector<int> ftIntIterator(5, 100);

        // Increment the first element of the vector using iterators
        std::vector<int>::iterator stdIt = stdIntIterator.begin();
        ++(*stdIt);

        ft::vector<int>::iterator ftIt = ftIntIterator.begin();
        ++(*ftIt);

        // Increment the last element of the vector using iterators
        std::vector<int>::iterator stdIt2 = stdIntIterator.end() - 1;
        ++(*stdIt2);

        ft::vector<int>::iterator ftIt2 = ftIntIterator.end() - 1;
        ++(*ftIt2);

        printVectorComparison(stdIntIterator, ftIntIterator);
    }
    {
        std::cout << "TESTING THE ASSIGN FUNCTION" << std::endl;
        std::vector<int> stdInt;
        ft::vector<int> ftInt;
        stdInt.assign(6, 5);
        ftInt.assign(6, 5);
        printVectorComparison(stdInt, ftInt);
    }

    {
        std::cout << "TESTING SWAP FUNCTION" << std::endl;
        std::vector<int> stdInt1;
        stdInt1.push_back(1);
        stdInt1.push_back(2);
        stdInt1.push_back(3);
        std::vector<int> stdInt2;
        stdInt2.push_back(4);
        stdInt2.push_back(5);
        stdInt2.push_back(6);
        ft::vector<int> ftInt1;
        ftInt1.push_back(1);
        ftInt1.push_back(2);
        ftInt1.push_back(3);
        ft::vector<int> ftInt2;
        ftInt2.push_back(4);
        ftInt2.push_back(5);
        ftInt2.push_back(6);

        std::cout << "Before swap:\n";
        printVectorComparison(stdInt1, ftInt1);
        printVectorComparison(stdInt2, ftInt2);

        stdInt1.swap(stdInt2);
        ftInt1.swap(ftInt2);

        std::cout << "After swap:\n";
        printVectorComparison(stdInt1, ftInt1);
        printVectorComparison(stdInt2, ftInt2);
    }
    {
        std::cout << "TESTING COMPARABILITY OF CONST ITERATORS AND ITERATORS" << std::endl;
        std::vector<int> stdInt;
        stdInt.push_back(1);
        stdInt.push_back(2);
        stdInt.push_back(3);
        stdInt.push_back(4);
        stdInt.push_back(5);
        ft::vector<int> ftInt;
        ftInt.push_back(1);
        ftInt.push_back(2);
        ftInt.push_back(3);
        ftInt.push_back(4);
        ftInt.push_back(5);

        // Compare const iterators with iterators
        std::vector<int>::const_iterator stdConstIt = stdInt.begin();
        std::vector<int>::iterator stdIt = stdInt.begin();
        ft::vector<int>::const_iterator ftConstIt = ftInt.begin();
        ft::vector<int>::iterator ftIt = ftInt.begin();

        std::cout << "Comparing const iterator with iterator:\n";
        std::cout << GREEN << "std::vector: " << (*stdConstIt == *stdIt) << DEFAULT << std::endl;
        std::cout << YELLOW << "ft::vector: " << (*ftConstIt == *ftIt) << DEFAULT << std::endl;
    }

}

class L
{
    public:
        int *p;
        L()
        {
            p = new int[1000];
        }
        L(const L &old)
        {
            p = new int[1000];
            std::copy(old.p, old.p + 1000, p);
        }
        L &operator=(const L &old)
        {
            if (this != &old)
            {
                delete[] p;
                p = new int[1000];
                std::copy(old.p, old.p + 1000, p);
            }
            return *this;
        }
        ~L()
        {
            delete[] p;
        }
};

void vector_allocation()
{
    ft::vector<L> a;
    a.insert(a.begin(), L());
    a.insert(a.begin(), 1000, L());
}

class MyVector {
public:
    MyVector() {
        // std::cout << "Constructing MyVector..." << std::endl;
    }

    ~MyVector() {
        // std::cout << "Destroying MyVector..." << std::endl;
    }
};

void nested_vectors() {
    ft::vector<ft::vector<ft::vector<MyVector> > > nestedVectors;

    std::cout << std::endl;
    std::cout << "Test For Memory Allocation, Object Construction, Resizing, and Nested Vector Behavior." << std::endl;
    std::cout << "Creating nested vectors..." << std::endl;
    nestedVectors.resize(3);

    for (int i = 0; i < 3; i++) {
        nestedVectors[i].resize(3);
        for (int j = 0; j < 3; j++) {
            nestedVectors[i][j].push_back(MyVector());
        }
    }
}