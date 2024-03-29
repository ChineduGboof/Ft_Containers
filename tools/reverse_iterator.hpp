/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:57:07 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/18 12:13:47 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
/**
 * The reverse_iterator class is a wrapper around an iterator 
 * that allows iterating in reverse order. 
 * It provides functionality to access elements in reverse, 
 * advance the iterator in the reverse direction, and perform arithmetic operations.
*/
namespace ft {

    template <class Iterator> 
    class reverse_iterator {
        public:

            typedef Iterator                                                    iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
            typedef typename ft::iterator_traits<Iterator>::reference           reference;

        private:
		    iterator_type    _currentPos;
        
        public:
            /*
            ** default constructor: 
            ** Constructs a reverse iterator that points to no object.
            ** The internal base iterator is value-initialized.
            */
            reverse_iterator() : _currentPos() {}
            
            /*
            ** initalization constructor: 
            ** Constructs a reverse iterator from some original iterator it.
            */
            reverse_iterator(iterator_type it) : _currentPos(it) {}

            /*
            ** copy / type-cast constructor: 
            ** Constructs a reverse iterator from some other reverse iterator
            */
            template <class T>
            reverse_iterator(const reverse_iterator<T> &other) : _currentPos(other.base()) {}

            reverse_iterator &operator=(const reverse_iterator &other) {
                if (this != &other) {
                    _currentPos = other.base();
                }
                return *this;
            }

            ~reverse_iterator() {}

            /*
            ** @brief: Returns a copy of the base iterator.
            */
            iterator_type base() const {
                return _currentPos;
            }

            /*
            ** @brief: Returns a reference to the element pointed to by the iterator.
            ** the function decreases a copy of its base iterator 
            ** and returns the result of dereferencing it.
            */
            reference operator*() const {
                iterator_type temp = _currentPos;
                return (*(--temp));
            }

            /*
            ** @brief: Returns a pointer to the element pointed to by the iterator
            ** Internally, the function calls operator* and returns its address 
            */
            pointer operator->() const {
                return &(operator*());
            }

            /*
            ** @brief: Accesses the element located n positions away 
            ** from the element currently pointed to by the iterator.
            ** Internally, the function accesses the proper element of its base iterator, 
            ** returning the same as: base()[-n-1]. 
            */
            reference operator[](difference_type n) const {
                return *(*this + n);
            };
            
            /*
            ** @brief: Returns a reverse iterator pointing to the element 
            ** located n positions away from the element the iterator currently points to.
            */
            reverse_iterator operator+(difference_type n) const {
                return reverse_iterator(_currentPos - n);
            }

            /*
            ** @brief: Advances the reverse_iterator by n element positions.
            */
            reverse_iterator &operator+=(difference_type n) {
                _currentPos -= n;
                return *this;
            }

            /**
            ** @brief: Advances the reverse_iterator by one position.
            **
            ** This member function is used to advance the reverse_iterator by one position.
            ** It decrements the current position (_currentPos) by one, indicating the reverse traversal.
            ** The function returns a reference to the updated reverse_iterator.
            */
            reverse_iterator &operator++() {
                --_currentPos;
                return *this;
            }

            /**
            ** @brief: Advances the reverse_iterator by one position.
            **
            ** This member function is used to advance the reverse_iterator by one position.
            ** It creates a temporary reverse_iterator (temp) initialized with the current reverse_iterator.
            ** Then, it increments the current reverse_iterator by calling the prefix increment operator (++(*this)).
            ** Finally, it returns the temporary reverse_iterator, representing the previous position before the increment.
            */
            reverse_iterator operator++(int) {
                reverse_iterator temp = *this;
                ++(*this);
                return temp;
            }

            /*
            ** @brief: Returns a reverse iterator pointing to the element 
            ** located n positions before the element the iterator currently points to.
            */
            reverse_iterator operator-(difference_type n) const {
                return reverse_iterator(_currentPos + n);
            }

            /*
            ** @brief: Descreases the reverse_iterator by n element positions.
            ** increases by n the base iterator kept by the object 
            ** (as if applying operator+= to it).
            */
            reverse_iterator &operator-=(difference_type n) {
                _currentPos += n;
                return *this;
            }

            /*
            ** @brief: Decreases the reverse_iterator by one position.
            */
            reverse_iterator &operator--() {
                ++_currentPos;
                return *this;
            }

            reverse_iterator operator--(int) {
                reverse_iterator temp = *this;
                --(*this);
                return temp;
            }
    };

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return x.base() == y.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return x.base() != y.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return x.base() > y.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return x.base() >= y.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return x.base() < y.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return x.base() <= y.base();
}

/**
 * Calculates the difference between two reverse iterators.
 * Subtracts the base iterator of the second iterator from the base iterator of the first iterator.
 * Returns the resulting difference.
 * @return Difference between the iterators.
 */
template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type
operator-(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return y.base() - x.base();
}

/**
 * Adds an integer value to a reverse iterator.
 * Creates and returns a new reverse iterator pointing to the element located n positions before
 * the element currently pointed to by the iterator.
 *
 * @param n Integer value representing the number of positions to move backward.
 * @param x Reverse iterator.
 * @return New reverse iterator.
 */
template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x) {
	return reverse_iterator<Iterator>(x.base() - n);
}

}   // namespace ft

#include "iterator_traits.hpp"
#endif