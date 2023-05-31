/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:03 by cegbulef          #+#    #+#             */
/*   Updated: 2023/05/31 12:33:58 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>
#include "../tools/reverse_iterator.hpp"
#include "../tools/lexicographical_compare.hpp"
#include "../tools/pair.hpp"

/*
For map I mostly just followed the geeksforgeeks implementation. 
It should give you a good foundation on the container. 
I spent most of my time in iterators and erase for map
*/

namespace ft {

template < class Key, class T, class Compare = std::less<Key>,  
            class Allocator = std::allocator<ft::pair<const Key,T> > > 
class map {
    typedef Key                                             key_type;
    typedef T                                               mapped_type;
    typedef ft::pair<const key_type, mapped_type>           value_type;
    typedef Compare                                         key_compare;
    typedef Allocator                                       allocator_type;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename allocator_type::pointer                pointer;
    typedef typename allocator_type::const_pointer          const_pointer;
    typedef typename allocator_type::size_type              size_type;
    typedef typename allocator_type::difference_type        difference_type;
    typedef avl_tree<key_type, mapped_type,
		                 key_compare, allocator_type>       tree_type;
	typedef map_iterator<value_type, key_compare>           iterator;
	typedef const_map_iterator<value_type, key_compare>     const_iterator;
    typedef ft::reverse_iterator<iterator>                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

    class value_compare: public binary_function<value_type, value_type, bool> {
            friend class map;
        protected:
            key_compare _comp;

            value_compare(key_compare c);
        public:
            bool operator()(const value_type& x, const value_type& y) const {
                return _comp(x.first, y.first);
            }
    };  // value_compare class


};

}   // namespace ft
#endif