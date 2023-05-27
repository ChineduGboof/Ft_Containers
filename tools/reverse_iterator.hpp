/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:07:28 by gboof             #+#    #+#             */
/*   Updated: 2023/05/27 21:50:25 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

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
            reverse_iterator() : _currentPos() {}

            reverse_iterator(iterator_type x) : _currentPos(x) {}

            template <class T>
            reverse_iterator(const reverse_iterator<T> &value) : _currentPos(value.base()) {}

            reverse_iterator &operator=(const reverse_iterator &value) {
                if (this != &value) {
                    _currentPos = value.base();
                }
                return *this;
            }

            ~reverse_iterator() {}

            iterator_type base() const {
                return _currentPos;
            }

            reference operator*() const {
                iterator_type temp = _currentPos;
                return *--temp;
            }

            pointer operator->() const {
                return &this->operator*();
            }

            reference operator[](difference_type n) const {
                return *(*this + n);
            };

            reverse_iterator operator+(difference_type n) const {
                return reverse_iterator(_currentPos - n);
            }

            reverse_iterator &operator+=(difference_type n) {
                _currentPos -= n;
                return *this;
            }

            reverse_iterator &operator++() {
                --_currentPos;
                return *this;
            }

            reverse_iterator operator++(int) {
                reverse_iterator temp(*this);
                --_currentPos;
                return temp;
            }

            reverse_iterator operator-(difference_type n) const {
                return reverse_iterator(_currentPos + n);
            }

            reverse_iterator &operator-=(difference_type n) {
                _currentPos += n;
                return *this;
            }

            reverse_iterator &operator--() {
                ++_currentPos;
                return *this;
            }

            reverse_iterator operator--(int) {
                reverse_iterator temp(*this);
                ++_currentPos;
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

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type
operator-(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	return y.base() - x.base();
}

template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x) {
	return reverse_iterator<Iterator>(x.base() - n);
}

}   // namespace ft

#include "iterator_traits.hpp"
#endif