/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:03 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 04:16:51 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../tools/reverse_iterator.hpp"
#include "../tools/lexicographical_compare.hpp"
#include "../tools/equal.hpp"
#include "../tools/avl_tree.hpp"
#include "stack.hpp"

/**
 * The map class is a container that stores elements as key-value pairs. 
 * It provides fast lookup and retrieval of values based on their associated keys.
*/
namespace ft {

template < class Key, class T, class Compare = std::less<Key>,  
            class Allocator = std::allocator<ft::pair<const Key,T> > > 
class map {
    public:
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
                            key_compare, allocator_type>        tree_type;
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

            value_compare(key_compare c) : _comp(c) {}
        public:
            bool operator()(const value_type& x, const value_type& y) const {
                return _comp(x.first, y.first);
            }
    };  // value_compare class

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
            : _comp(comp), _alloc(alloc), _size() {
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
        map &operator=(const map& x) {
            this->clear();
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

        /**
         * Inserts a key-value pair into the map.
         * @param val The key-value pair to be inserted.
         * @return A pair consisting of an iterator to the inserted element and a boolean value.
         *         The iterator points to the inserted element if the insertion is successful,
         *         or to the existing element if the key already exists.
         *         The boolean value is true if the insertion is successful, false otherwise.
         * Check if the element already exists in the map. If it doesnt, it will return the endNode
         * Insert the new element into the map and update the root
         * Return an iterator to the inserted element and true to indicate successful insertion
         */
        ft::pair<iterator, bool> insert(const value_type& val) {
            iterator existing = this->find(val.first);
            if (existing != end()) {
                return ft::make_pair(existing, false);
            }
            _tree.updateRoot(_tree.insertNode(_tree.getRoot(), val));
            _size++;
            return ft::make_pair(this->find(val.first), true);
        }

        /**
            Inserts a key-value pair into the map at the specified position.
            The position parameter is ignored in this implementation.
            The function first calls the insert function to insert the element into the map.
            Then, it returns an iterator to the element with the specified key, using the find function.
            @param position An iterator pointing to the position where the element should be inserted (ignored).
            @param val The key-value pair to be inserted.
            @return An iterator to the inserted element or to the element with the equivalent key.
        */
        iterator insert (iterator position, const value_type& val) {
            (void)position;
            this->insert(val);
            return this->find(val.first);
        }

        /**
            Inserts a range of elements into the map.
            The function iterates over the range defined by the input iterators, calling the insert function for each element.
            It uses the first and last iterators to determine the range of elements to be inserted.
            @tparam InputIterator The type of the input iterators representing the range of elements.
            @param first An input iterator pointing to the first element in the range.
            @param last An input iterator pointing to the element one past the last element in the range.
            @note The range is defined as [first, last), where 'first' is included and 'last' is excluded.
            @note The elements are inserted in the order they appear in the range.
        */
        template <class InputIterator>  void insert (InputIterator first, InputIterator last) {
            while ( first != last) {
                this->insert(*first);
                first++;
            }
        }

        /**
         * Erases the element at the specified position in the map.
         * @param position An iterator pointing to the element to be removed.
         * @note The iterator must be valid and dereferenceable.
         * @note After erasing the element, the iterator becomes invalid.
         * Handle the case where the iterator points to the end() position
         * Delete the node containing the element from the underlying tree
         */
        void erase (iterator position)
		{ if (position.base() == _tree.getEndNode()) {
				std::cout << position.base()->right->value.first << std::endl;
			}
			_tree.updateRoot(_tree.deleteNode(_tree.getRoot(), ft::make_pair(position->first, position->second)));
			_size--;
         }

        /**
         * Erases all elements with the specified key from the map.
         * @param k The key of the element(s) to be removed.
         * @return The number of elements erased (0 or 1, since the map contains unique keys).
         * @note This function removes all elements with the specified key from the map.
         *       It first checks if the key exists in the map by using find(k).base().
         *       If the key is found (i.e., the iterator is not pointing to the end() position),
         *       it calls the erase(iterator position) function with the iterator returned by find(k)
         *       to remove the element.
        */
        size_type erase(const key_type &k) {
			if (this->find(k).base() != _tree.getEndNode()) {
				this->erase(this->find(k));
				return 1;
			}
			return 0;
		}

        /**
         * Erases a range of elements from the map.
         * @param first An iterator pointing to the first element of the range to be removed.
         * @param last An iterator pointing to the element one past the last element of the range to be removed.
         * @note The range is defined as [first, last), where 'first' is included and 'last' is excluded.
         * @note After erasing the elements, the iterators in the range become invalid.
        */
       void erase(iterator first, iterator last) {
			ft::stack<key_type> temp;
			for (iterator it = first; it != last; it++) {
				temp.push(it->first);
			}
			for (; !temp.empty(); temp.pop()) {
				this->erase(temp.top());
			}
		}

        /**
            Swaps the contents of this map with another map.
            The internal data members, including the underlying tree, key comparator,
            allocator, and size, are exchanged between the two maps.
            This operation effectively swaps the entire state of the maps,
            providing a fast way to exchange their contents.
            @param x The map to swap the contents with.
        */
        void swap(map &x) {
			tree_type temp_tree = _tree;
			key_compare temp_comp = _comp;
			allocator_type temp_alloc = _alloc;
			size_type temp_size = _size;

			_tree = x._tree;
			_comp = x._comp;
			_alloc = x._alloc;
			_size = x._size;

			x._tree = temp_tree;
			x._comp = temp_comp;
			x._alloc = temp_alloc;
			x._size = temp_size;
		}
        
        /**
            Clears the map, removing all elements.
            It calls the clear() function on the underlying tree to remove all nodes.
            After clearing the map, the size is set to 0.
        */
        void clear() {
            _tree.clear(_tree.getRoot(), false);
            _size = 0;
        }

        /************************ OBSERVERS ************************/
        /**
            Returns a copy of the key comparison object used by the map container.
            The key comparison object determines the order of the elements based on their keys.
            It is a function pointer or function object that compares two keys and returns true
            if the first key is considered to go before the second key.
        */
        key_compare key_comp() const{
            return _comp;
        }
        
        /**
            Returns a copy of the value comparison object used by the map container.
            The value comparison object is derived from the key comparison object.
            It is used to compare two elements to determine whether the key of the first element
            goes before the key of the second element. The mapped_type part of the value is not
            taken into consideration in this comparison.
        */
        value_compare value_comp() const{
            return value_compare(this->key_comp());
        }

        /************************ OPERATIONS ************************/

        /**
            Find function
            Searches for the element with the specified key in the map.
            @param k The key value to search for.
            @return An iterator pointing to the found element, or an iterator pointing to the end position if the key is not found.
            Algorithm:
            Call the search function on the underlying tree, passing the root node and the key value.
            Construct and return an iterator using the returned node, the root node of the tree, and the end node.
            This allows users to efficiently find elements in the map using their keys.
            if the search function returns a null pointer, 
            the iterator constructed with it will be pointing to the end position of the map
            iterator(node, root, endnode)
        */

		iterator find(const key_type &k) {
			return iterator(_tree.search(_tree.getRoot(), k), _tree.getRoot(), _tree.getEndNode());
		}

		const_iterator find(const key_type &k) const {
			return const_iterator(_tree.search(_tree.getRoot(), k), _tree.getRoot(), _tree.getEndNode());
		}
        
        /**
         * Count function
         * Returns the number of elements with the specified key in the map.
         * @param k The key value to count.
         * @return The number of elements with the specified key (0 or 1, since the map contains unique keys).
         * Algorithm:
         * Call the find function to search for the specified key in the map.
         * If the find function returns an iterator pointing to the end position, return 0.
         * Otherwise, return 1.
         * This function provides a convenient way to check the existence of a key in the map and count its occurrences.
         * The base() converts the iterator output of find() to a point that can be used in == comparison
        */

        size_type count(const key_type &k) const {
			return this->find(k).base() == _tree.getEndNode() ? 0 : 1;
		}

        /**
         * Lower bound function
         * Returns an iterator pointing to the first element that is not less than the specified key.
         * @param k The key value to compare against.
         * @return An iterator pointing to the first element not less than the specified key.
         * Algorithm:
         * Call the find function to search for the specified key in the map.
         * If the find function returns an iterator pointing to the end position, return an iterator pointing to the successor key.
         * Otherwise, return the found iterator.
         * This function provides a way to efficiently find the lower bound position for a given key in the map.
        */

		iterator lower_bound(const key_type &k) {
			return this->find(k).base() != _tree.getEndNode() ? this->find(k) :
			       iterator(_tree.getKeySuccessor(_tree.getRoot(), k), _tree.getRoot(), _tree.getEndNode());
		}

		const_iterator lower_bound(const key_type &k) const {
			return this->find(k).base() != _tree.getEndNode() ? this->find(k) :
			       const_iterator(_tree.getKeySuccessor(_tree.getRoot(), k), _tree.getRoot(), _tree.getEndNode());
		}

        /**
         * Upper bound function
         * Returns an iterator pointing to the first element that is greater than the specified key.
         * @param k The key value to compare against.
         * @return An iterator pointing to the first element greater than the specified key.
         * Algorithm:
         * Call the getKeySuccessor function on the underlying tree, passing the root node and the key value.
         * Construct and return an iterator using the returned successor key and the root and end nodes of the tree.
         * This function allows users to efficiently find the upper bound position for a given key in the map.
         */
		iterator upper_bound(const key_type &k) {
			return iterator(_tree.getKeySuccessor(_tree.getRoot(), k), _tree.getRoot(), _tree.getEndNode());
		}

		const_iterator upper_bound(const key_type &k) const {
			return const_iterator(_tree.getKeySuccessor(_tree.getRoot(), k), _tree.getRoot(), _tree.getEndNode());
		}

        /**
         * Equal range function
         * Returns a pair of iterators representing the range of elements with the specified key.
         * @param k The key value to compare against.
         * @return A pair of iterators representing the range of elements with the specified key.
         * Algorithm:
         * Call the lower_bound and upper_bound functions to find the lower bound and upper bound positions for the specified key.
         * Create a pair using the lower bound and upper bound iterators and return it.
         * This function provides a convenient way to obtain the range of elements with a given key in the map.
        */
		ft::pair<iterator, iterator> equal_range(const key_type &k) {
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}


        /************************ ALLOCATOR ************************/
        /*
        **  Returns a copy of the allocator object associated with the map.
        */
        allocator_type get_allocator() const{
            return _alloc;
        }

    private:
		tree_type         _tree;
		key_compare       _comp;
		allocator_type    _alloc;
		size_type         _size;

};  // map class

template <class Key, class T, class Compare, class Allocator>
bool operator==(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs) {
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs) {
	return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Allocator>
bool operator>(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs) {
	return rhs < lhs;
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs) {
	return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Allocator>
void swap(ft::map<Key, T, Compare, Allocator> &lhs, ft::map<Key, T, Compare, Allocator> &rhs) {
	lhs.swap(rhs);
}

}   // namespace ft
#endif