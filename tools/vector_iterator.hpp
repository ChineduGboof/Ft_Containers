/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:57:24 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/04 21:04:00 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "iterator_traits.hpp"

// #include <vector>
// #include <iterator>

namespace ft {

    template<class T>
    class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
        public:
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>    traits;
            typedef typename traits::value_type                                 value_type;
            typedef typename traits::difference_type                            difference_type;
            typedef typename traits::pointer                                    pointer;
            typedef typename traits::reference                                  reference;
            typedef typename traits::iterator_category                          iterator_category;

        private:
            pointer _currentPos;  // Pointer to the element in the vector
        
        public:
            vector_iterator(): _currentPos() {}

            vector_iterator(pointer currentPos) : _currentPos(currentPos) {}
            
            template <class U>
            vector_iterator(const vector_iterator<U>& other) : _currentPos(other.base()) {}

            vector_iterator& operator=(const vector_iterator& other) {
                if (this != &other) {
                    _currentPos = other._currentPos;
                }
                return *this;
            }

            ~vector_iterator() {}
            
            // @return The base pointer representing the current position of the iterator.
            pointer base() const {
			    return _currentPos;
		    }

            // Overload dereference operator (*)
            reference operator*() const {
                return *_currentPos;
            }

            // Overload arrow operator (->)
            pointer operator->() const {
                return _currentPos;
            }

             // Overload subscript operator (it[n])
            reference operator[](difference_type n) const {
                return _currentPos[n];
            }

            // Overload addition operator (it + n)
            vector_iterator operator+(difference_type n) const {
                return vector_iterator(_currentPos + n);
            }

            // Overload subtraction operator (it - n)
            vector_iterator operator-(difference_type n) const {
                return vector_iterator(_currentPos - n);
            }

            // Overload pre-increment operator (++it)
            vector_iterator& operator++() {
                ++_currentPos;
                return *this;
            }

            // Overload post-increment operator (it++)
            vector_iterator operator++(int) {
                vector_iterator temp = *this;
                ++(*this);
                return temp;
            }

            // Overload pre-decrement operator (--it)
            vector_iterator& operator--() {
                --_currentPos;
                return *this;
            }

            // Overload post-decrement operator (it--)
            vector_iterator operator--(int) {
                vector_iterator temp = *this;
                --(*this);
                return temp;
            }

            // Overload addition assignment operator (it += n)
            vector_iterator& operator+=(difference_type n) {
                _currentPos += n;
                return *this;
            }

            // Overload subtraction assignment operator (it -= n)
            vector_iterator& operator-=(difference_type n) {
                _currentPos -= n;
                return *this;
            }

    };

    // Overload equality operator (it == other)
    template <class Iterator1, class Iterator2>
    bool operator==(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs) {
        return lhs.base() == rhs.base();
    }

    // Overload inequality operator (it != other)
    template <class Iterator1, class Iterator2>
    bool operator!=(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs) {
        return lhs.base() != rhs.base();
    }

    // Overload less than operator (it < other)
    template <class Iterator1, class Iterator2>
    bool operator<(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs) {
        return lhs.base() < rhs.base();
    }

    // Overload greater than operator (it > other)
    template <class Iterator1, class Iterator2>
    bool operator>(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs) {
        return lhs.base() > rhs.base();
    }

    // Overload less than or equal to operator (it <= other)
    template <class Iterator1, class Iterator2>
    bool operator<=(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs) {
        return lhs.base() <= rhs.base();
    }

    // Overload greater than or equal to operator (it >= other)
    template <class Iterator1, class Iterator2>
    bool operator>=(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs) {
        return lhs.base() >= rhs.base();
    }

    // Overload subtraction operator (it - it)
    template <class Iterator>
    typename vector_iterator<Iterator>::difference_type
    operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
        return lhs.base() - rhs.base();
    }

    // Overload subtraction operator (it_L - it_R)
    template <class Iterator_L, class Iterator_R>
    typename vector_iterator<Iterator_L>::difference_type
    operator-(const vector_iterator<Iterator_L> &lhs, const vector_iterator<Iterator_R> &rhs) {
        return lhs.base() - rhs.base();
    }

    // Overload addition operator (it + n)
    template <class Iterator>
    vector_iterator<Iterator>
    operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it) {
        return vector_iterator<Iterator>(it.base() + n);
    }

}   //  namespace ft

#endif // !ITERATOR_HPP
