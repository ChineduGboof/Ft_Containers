/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:37:31 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/03 18:54:36 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "avl_tree_node.hpp"
#include "map_navigator.hpp"

namespace ft {
    /*************************************Map Iterator ***********************************/

    template<class T, class Compare>
    class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
        public:
            typedef Compare                                                     key_compare;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>    traits;
            typedef typename traits::value_type                                 value_type;
            typedef typename traits::difference_type                            difference_type;
            typedef typename traits::pointer                                    pointer;
            typedef typename traits::reference                                  reference;
            typedef typename traits::iterator_category                          iterator_category;
            typedef avlTreeNode<value_type>                                     node_type;
            typedef node_type*                                                  node_pointer;
            typedef map_navigator<value_type, key_compare>                      node_finder;

        private:
            node_pointer _node;
            node_pointer _root;
            node_pointer _sentinel;
            key_compare _comp;
            node_finder _find; 
        
        public:
            map_iterator() : _node(), _root(), _sentinel(), _comp(), _find() {}

            map_iterator(node_pointer node, node_pointer root, node_pointer sentinel,
		             const key_compare &comp = key_compare()) 
                     : _node(node), _root(root), _sentinel(sentinel), _comp(comp), 
                        _find(_node, _root, _sentinel, _comp) {}

            map_iterator(const map_iterator &other) 
                : _node(other._node), _root(other._root), _sentinel(other._sentinel),
                    _comp(other._comp), _find(_node, _root, _sentinel, _comp) {}

            map_iterator &operator=(const map_iterator &other) {
                if (this != &other) {
                    _node = other._node;
                    _root = other._root;
                    _sentinel = other._sentinel;
                    _comp = other._comp;
                    _find = node_finder(_node, _root, _sentinel, _comp);
                }
                return *this;
            }

            ~map_iterator() {}

            // Returns a reference to the value stored in the current node.
            reference operator*() const {
                return _node->value;
            }

            // Returns a pointer to the value stored in the current node. 
            // If the current node is NULL, returns a pointer to the value of the sentinel node.
            pointer operator->() const {
                return _node ? &_node->value : &_sentinel->value;
            }

            // Returns the pointer to the current node.
            node_pointer base() const {
                return _node;
            }

            // Returns the pointer to the root node of the AVL tree.
            node_pointer getRoot() const {
                return _root;
            }

            // Returns the pointer to the sentinel node of the AVL tree.
            node_pointer getSentinel() const {
                return _sentinel;
            }

            // Returns the key comparison functor used for comparing keys in the AVL tree.
            key_compare getComp() const {
                return _comp;
            }

            // Prefix increment operator (++iterator). 
            // Moves the iterator to the next node in the AVL tree.
            map_iterator &operator++() {
                _node = _find.getSuccessor(_root, _node);
                return *this;
            }

            // Postfix increment operator (iterator++). 
            // Moves the iterator to the next node in the AVL tree 
            // and returns a copy of the iterator before the increment.
            map_iterator operator++(int) {
                map_iterator temp = *this;
                ++(*this);
                return temp;
            }

            // Prefix decrement operator (--iterator). 
            // Moves the iterator to the previous node in the AVL tree.
            map_iterator &operator--() {
                _node = _find.getPredecessor(_root, _node);
                return *this;
            }

            // Postfix decrement operator (iterator--). 
            // Moves the iterator to the previous node in the AVL tree 
            // and returns a copy of the iterator before the decrement.
            map_iterator operator--(int) {
                map_iterator temp = *this;
                --(*this);
                return temp;
            }
    };  //map_iterator

template <class T, class Compare>
bool operator==(const ft::map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	return !(lhs == rhs);
}

/*************************************Const Map Iterator ***********************************/


template <class T, class Compare>
class const_map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

	public:
		typedef Compare                                             key_compare;
		typedef ft::iterator<std::bidirectional_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;
		typedef const value_type*                                   pointer;
		typedef const value_type&                                   reference;
		typedef avlTreeNode<value_type>                             node_type;
		typedef node_type*                                          node_pointer;
		typedef map_iterator<value_type, key_compare>               iterator;
		typedef map_navigator<value_type, key_compare>              node_finder;

	private:
		node_pointer _node;
		node_pointer _root;
		node_pointer _sentinel;
		key_compare _comp;
		node_finder _find;

	public:
		const_map_iterator() : _node(),
		                       _root(),
		                       _sentinel(),
		                       _comp(),
		                       _find() {}

		const_map_iterator(const node_pointer node, node_pointer root, node_pointer sentinel,
		                   const key_compare &comp = key_compare()) : _node(node),
		                                                              _root(root),
		                                                              _sentinel(sentinel),
		                                                              _comp(comp),
		                                                              _find(_node, _root, _sentinel, _comp) {}

		const_map_iterator(const iterator &other) : _node(other.base()),
		                                            _root(other.getRoot()),
		                                            _sentinel(other.getSentinel()),
		                                            _comp(other.getComp()),
		                                            _find(_node, _root, _sentinel, _comp) {}

		const_map_iterator(const const_map_iterator &other) : _node(other._node),
		                                                      _root(other._root),
		                                                      _sentinel(other._sentinel),
		                                                      _comp(other._comp),
		                                                      _find(_node, _root, _sentinel, _comp) {}

		const_map_iterator &operator=(const const_map_iterator &other) {
			if (this != &other) {
				_node = other._node;
				_root = other._root;
				_sentinel = other._sentinel;
				_comp = other._comp;
				_find = node_finder(_node, _root, _sentinel, _comp);
			}
			return *this;
		}

		~const_map_iterator() {}

		reference operator*() const {
			return _node->value;
		}

		pointer operator->() const {
			return _node ? &_node->value : &_sentinel->value;
		}

		node_pointer base() const {
			return _node;
		}

		const_map_iterator &operator++() {
			_node = _find.getSuccessor(_root, _node);
			return *this;
		}

		const_map_iterator operator++(int) {
			const_map_iterator temp = *this;
			++(*this);
			return temp;
		}

		const_map_iterator &operator--() {
			_node = _find.getPredecessor(_root, _node);
			return *this;
		}

		const_map_iterator operator--(int) {
			const_map_iterator temp = *this;
			--(*this);
			return temp;
		}

};    // class const_map_iterator

/*
**  These operators compare two const_map_iterator objects for equality and inequality, respectively.
*/
template <class T, class Compare>
bool operator==(const ft::const_map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::const_map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return !(lhs == rhs);
}

/************************************* OVERLOAD OPERATORS **********************************/
/*
**  These operators compare a map_iterator object and a const_map_iterator object for equality and inequality, respectively.
*/
template <class T, class Compare>
bool operator==(const ft::map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return !(lhs == rhs);
}

/*
**  These operators compare a const_map_iterator object and a map_iterator object for equality and inequality, respectively.
*/
template <class T, class Compare>
bool operator==(const ft::const_map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	ft::const_map_iterator<T, Compare> const_rhs(rhs);
	return lhs.base() == const_rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::const_map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	ft::const_map_iterator<T, Compare> const_rhs(rhs);
	return !(lhs.base() == const_rhs.base());
}

}   // namespace ft
#endif