/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:05:54 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 21:20:53 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP
#define NAMESPACE ft
#include <iostream>
#include <vector>
#include <map>
#include <stack>

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"

#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
#include "../tools/avl_tree.hpp"

template <typename Key, typename T>
bool isMapOrdered(const ft::map<Key, T>& map) {
    typename ft::map<Key, T>::const_iterator it = map.begin();
    typename ft::map<Key, T>::const_iterator next = it;
    ++next;
    while (next != map.end()) {
        if (map.key_comp()((*next).first, (*it).first))
            return false;
        ++it;
        ++next;
    }
    return true;
}

// Function to print the elements of the map in pre-order traversal
template<typename Key, typename T, typename Compare, typename Alloc>
void printPreOrder(const ft::map<Key, T, Compare, Alloc>& map) {
    typename ft::map<Key, T, Compare, Alloc>::const_iterator it;
    for (it = map.begin(); it != map.end(); ++it) {
        std::cout << "Key = " << it->first
                  << "\t\tValue = " << it->second << std::endl;
    }
}

void vector_tests();
void vector_allocation();
void nested_vectors();
void mapTests();
void stackTests();

#endif