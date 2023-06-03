/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:03 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/04 01:19:13 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>
#include "../tools/reverse_iterator.hpp"
#include "../tools/map_iterator.hpp"
#include "../tools/lexicographical_compare.hpp"
#include "../tools/pair.hpp"
#include "../tools/equal.hpp"
#include "../tools/avl_tree.hpp"

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

    /**
        Custom comparator class for comparing the values of key-value pairs in a map.
        Inherits from std::binary_function and provides an operator() for comparing values.
        the friend keyword is used to grant access to private or protected members of a class 
        to another class or function. When a class or function is declared as a friend 
        of another class, it can access the private and protected members of that class 
        as if it were a member of that class itself.
        his means that the map class has access to the 
        private and protected members of the value_compare class.
        This allows the map class to create instances of the value_compare class 
        and use its private member _comp for value comparison.
    */
    class value_compare: public std::binary_function<value_type, value_type, bool> {
            friend class map;
        protected:
            key_compare _comp;

            value_compare(key_compare c);
        public:
            bool operator()(const value_type& x, const value_type& y) const {
                return _comp(x.first, y.first);
            }
    };  // value_compare class

    private:
		tree_type         _tree;
		key_compare       _comp;
		allocator_type    _alloc;
		size_type         _size;

    public:
        /*
        **  Constructs an empty container, with no elements.
        */
        explicit map (const key_compare& comp = key_compare(), 
            const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc), _size() {}

        /*
        **  Constructs a container with as many elements as the range [first,last), 
        **  with each element constructed from its corresponding element in that range.
        */
        template <class InputIterator>  map (InputIterator first, InputIterator last, 
            const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _comp(comp), _alloc(alloc), _size(0) {
                this->insert(first, last);
        }

        /*
        **  Constructs a container with a copy of each of the elements in x.
        */
        map (const map& x): _comp(x._comp), _alloc(x._alloc), _size() {
            this->insert(x.begin(), x.end());
        }

        /*
        **  Assigns new contents to the container, replacing its current content.
        **  Copies all the elements from x into the container, changing its size accordingly.
        */
        map& operator= (const map& x) {
            if (this != &x){
                _comp = x._comp;
                _alloc = x._alloc;
            }
            this->insert(x.begin(), x.end());
            return *this;
        }

        /*
        **  Destroys the container object.
        */
        ~map(){ 
            _tree.clear(_tree.getRoot(), true);
        }
        
        /************************ ITERATORS ************************/
        /*
        **  the begin() function returns an iterator that points to the first element in the map. 
        **  If the map is empty, it returns an iterator pointing to the end Node. 
        **  If the map is not empty, it returns an iterator pointing 
        **  to the element with the smallest key in the map.
        **  If the container is empty, the returned iterator value shall not be dereferenced.
        */
        iterator begin() {
            if (!_tree.getRoot()) {
                return iterator(_tree.getEndNode(), _tree.getRoot(), _tree.getEndNode());
            } else {
                return iterator(_tree.getMinimum(_tree.getRoot()), _tree.getRoot(), _tree.getEndNode());
            }
        }

        const_iterator begin() const {
            if (!_tree.getRoot()) {
                return const_iterator(_tree.getEndNode(), _tree.getRoot(), _tree.getEndNode());
            } else {
                return const_iterator(_tree.getMinimum(_tree.getRoot()), _tree.getRoot(), _tree.getEndNode());
            }
        }

        /**
            Returns an iterator representing the end of the map.
            The end iterator points to a special sentinel node that indicates the end of the map.
            It is constructed using the end node, root node, and the sentinel node of the map.
        */
        iterator end() {
			return iterator(_tree.getEndNode(), _tree.getRoot(), _tree.getEndNode());
		}

		const_iterator end() const {
			return const_iterator(_tree.getEndNode(), _tree.getRoot(), _tree.getEndNode());
		}

        /**
            Returns a reverse iterator pointing to the last element of the map.
            It is constructed by calling the end() function to get the end iterator, and then constructing a reverse iterator from it.
        */
        reverse_iterator rbegin() {
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->end());
		}

        /**
            Returns a reverse iterator pointing to the theoretical element 
            preceding the first element of the map.
            It is constructed by calling the begin() function to get the 
            begin iterator, and then constructing a reverse iterator from it.
        */
		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->begin());
		}

        /************************ CAPACITY ************************/
        /*
        ** @brief Returns whether the container is empty.
        ** Does not modify container in any way.
        ** @return true if the container size is 0, false otherwise.
        */
        bool empty() const {
			return _size == 0;
		}

        /**
            @brief return the number of elements in the container.
            @return the number of elements.
        */
		size_type size() const {
			return _size;
		}

        /**
         * Returns the maximum number of elements that the map can hold.
        */
		size_type max_size() const {
			return _tree.max_size();
		}

        /************************ ELEMENT ACCESS ************************/
        /*
        **  If k matches the key of an element in the container, 
        **  the function returns a reference to its mapped value.
        **  If k does not match the key of any element in the container, 
        **  the function inserts a new element with that key 
        **  and returns a reference to its mapped value. 
        */
        mapped_type& operator[] (const key_type& k){
            return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
        }


        /************************ MODIFIERS ************************/

        pair<iterator,bool> insert (const value_type& val);


        
        /************************ ALLOCATOR ************************/
        /*
        **  Returns a copy of the allocator object associated with the map.
        */
        allocator_type get_allocator() const{
            return _alloc;
        }



};

}   // namespace ft
#endif