/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:32 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/08 22:14:03 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

/************MAIN TO CHECK THE CONSTRUCTORS *******************/

void    constructors()
{
	std::cout << "Checking the default constructor" << std::endl;
	std::vector<int> myInt;
	ft::vector<int> myFtInt;

	std::cout << "default size: " << GREEN << myInt.size() << YELLOW <<  myFtInt.size() << std::endl;

	//	Checking the fill constructor
	std::vector<int> myIntFill(5, 4);
	ft::vector<int> myFtIntFill2(5, 4);
	std::cout << "fill size: " << myIntFill.size() << std::endl;

	// myIntFill2[1]
	// *myIntFill2 + 1

	std::vector<int>::const_iterator test = myIntFill.begin() + 3;
	std::cout << *test << std::endl;
}
