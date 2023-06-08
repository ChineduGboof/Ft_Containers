/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:32 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/08 22:41:15 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename T>
void printVectorComparison(const std::vector<T>& stdVec, const ft::vector<T>& ftVec) {
    typename std::vector<T>::const_iterator stdIt = stdVec.begin();
    typename ft::vector<T>::const_iterator ftIt = ftVec.begin();

    std::cout << "std::vector: ";
    for (; stdIt != stdVec.end(); ++stdIt)
        std::cout << *stdIt << " ";

    std::cout << "\nft::vector:  ";
    for (; ftIt != ftVec.end(); ++ftIt)
        std::cout << *ftIt << " ";

    std::cout << std::endl;
}

void constructors() {
    std::cout << "Checking the default constructor" << std::endl;
    std::vector<int> stdInt;
    ft::vector<int> ftInt;

    std::cout << "default size: " << GREEN << stdInt.size() << YELLOW << ftInt.size() << DEFAULT << std::endl;

    // Checking the fill constructor
    std::vector<int> stdIntFill(5, 4);
    ft::vector<int> ftIntFill(5, 4);

    std::cout << "fill size: " << stdIntFill.size() << std::endl;
    printVectorComparison(stdIntFill, ftIntFill);
}