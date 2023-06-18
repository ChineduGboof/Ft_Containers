/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:00:55 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/18 12:11:29 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

template <class T1, class T2> struct pair {
	typedef T1 first_type;
	typedef T2 second_type;

	first_type  first;
	second_type second;

	/*
	**	Default Constructor
	**	Constructs a pair object with its elements value-initialized.
	*/
	pair(): first(), second() {}

	/*
	**	Copy Constructor
	**	The object is initialized with the contents of the pr pair object.
	**	The corresponding member of pr is passed to the constructor of each of its members
	*/
	template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}

	/*
	**	initialization constructor
	**	Member first is constructed with a and member second with b.
	*/
	pair (const first_type& a, const second_type& b): first(a), second(b) {}

	/*
	**	Assigns pr as the new content for the pair object.
	**	Member first is assigned pr.first, and member second is assigned pr.second.
	*/
	pair& operator= (const pair& pr){
		if (this != &pr) {
			first = pr.first;
			second = pr.second;
		}
		return *this;
	}
};

// operator== - Equality comparison operator for pairs.

template <class T1, class T2>
bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
    return lhs.first == rhs.first && lhs.second == rhs.second; 
}

// operator!= - Inequality comparison operator for pairs.

template <class T1, class T2>
bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
    return !(lhs == rhs); 
}

// operator< - Less than comparison operator for pairs.

template <class T1, class T2>
bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
    return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); 
}

// operator<= - Less than or equal to comparison operator for pairs.

template <class T1, class T2>
bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
    return !(rhs < lhs); 
}

// operator> - Greater than comparison operator for pairs.

template <class T1, class T2>
bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
    return rhs < lhs; 
}

// operator>= - Greater than or equal to comparison operator for pairs.

template <class T1, class T2>
bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
    return !(lhs < rhs); 
}

/**
 * make_pair - Creates a pair object.
 * This function template creates and returns a pair object with the provided values of type T1 and T2.
 * It takes two arguments, 'x' and 'y', representing the values to be stored in the pair's first and second elements, respectively.
 * The function constructs a pair object using the provided values and returns it.
 *
 * @param x - The value to be stored in the first element of the pair.
 * @param y - The value to be stored in the second element of the pair.
 * @tparam T1 - The type of the first element.
 * @tparam T2 - The type of the second element.
 * @return A pair object with the specified values.
 * The template types can be implicitly deduced from the arguments passed to make_pair.
 */
template <class T1,class T2>
ft::pair<T1,T2> make_pair (T1 x, T2 y) {
    return ( ft::pair<T1,T2>(x,y) );
  }

}   // namespace ft

#endif