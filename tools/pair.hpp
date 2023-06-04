/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:00:55 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/04 21:03:30 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP
// #include <map>

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

template <class T1, class T2>
bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
	return lhs.first==rhs.first && lhs.second==rhs.second; 
}

template <class T1, class T2>
bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
	return !(lhs==rhs); 
}

template <class T1, class T2>
bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
}

template <class T1, class T2>
bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
	return !(rhs<lhs); 
}

template <class T1, class T2>
bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
	return rhs<lhs; 
}

template <class T1, class T2>
bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { 
	return !(lhs<rhs); 
}

/*
**	Constructs a pair object with its first element set to x and its second element set to y.
**	The template types can be implicitly deduced from the arguments passed to make_pair.
*/
template <class T1,class T2>
ft::pair<T1,T2> make_pair (T1 x, T2 y) {
    return ( ft::pair<T1,T2>(x,y) );
  }

}   // namespace ft

#endif