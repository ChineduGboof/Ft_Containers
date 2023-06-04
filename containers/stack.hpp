/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:13:55 by gboof             #+#    #+#             */
/*   Updated: 2023/06/04 21:49:36 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

    template <class T, class Container = ft::vector<T> > class stack {

    public:
		typedef Container                                   container_type;
		typedef typename container_type::value_type         value_type;
		typedef typename container_type::size_type          size_type;
		typedef typename container_type::reference          reference;
		typedef typename container_type::const_reference    const_reference;

	protected:
		container_type    container;

    
	public:
        /**
         * Constructs a stack container adaptor object.
        */
		explicit stack(const container_type& ctnr = container_type()) : container(ctnr) {}

        /**
         * Returns whether the stack is empty: i.e. whether its size is zero.
        */
		bool empty() const {
			return container.empty();
		}

        /**
         * Returns the number of elements in the stack.
        */
		size_type size() const {
			return container.size();
		}
        
        /**
         * Returns a reference to the top element in the stack.
         * Since stacks are last-in first-out containers, 
         * the top element is the last element inserted into the stack.
         * This member function effectively calls member back of the underlying container object.
        */
		reference top() {
			return container.back();
		}

		const reference top() const {
			return container.back();
		}

        /**
         * Inserts a new element at the top of the stack, above its current top element.
         * This member function effectively calls the member function 
         * push_back of the underlying container object.
        */
		void push(const value_type &value) {
			container.push_back(value);
		}

        /**
         * Removes the element on top of the stack, effectively reducing its size by one.
         * This member function effectively calls the member function 
         * pop_back of the underlying container object.
        */
		void pop() {
			container.pop_back();
		}

        /**
         * The friend keyword is used for the comparison operators 
         * to allow them access to the private members of the stack class. 
         * This enables them to directly compare the underlying containers of two stack objects.
         * These two operators need access to the private member "container" of the stack class.
        */
		friend bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
			return lhs.container == rhs.container;
		}

		friend bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
			return lhs.container < rhs.container;
		}

    };

template <class T, class Container>
bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Container>
bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Container>
bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return rhs < lhs;
}

template <class T, class Container>
bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return !(lhs < rhs);
}


}   // namespace ft

#endif // !STACK_HPP