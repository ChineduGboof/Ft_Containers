/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_validity.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:56:46 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/18 12:02:37 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_VALIDITY_HPP
#define ITERATOR_VALIDITY_HPP

#include "iterator_traits.hpp"

/** 
 * iterator_validity - Checks the validity of the iterators based on their iterator category.
 *
 * This function template is used to check the validity of iterators based on their iterator category.
 * It provides specific implementations for different iterator categories, such as input iterators,
 * output iterators, forward iterators, bidirectional iterators, and random access iterators. 
 * For each category, the function performs appropriate validity checks or throws an exception if necessary.
 *
 * @param first - The first iterator of the range.
 * @param last - The last iterator of the range.
 * @tparam Iter - The type of the iterators.
 */

namespace ft {

// No validity checks are performed for input iterators.
template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::input_iterator_tag) {
	(void)first;
	(void)last;
}

// No validity checks are performed for output iterators.
template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::output_iterator_tag) {
	(void)first;
	(void)last;
}

// No validity checks are performed for forward iterators.
template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::forward_iterator_tag) {
	(void)first;
	(void)last;
}

// No validity checks are performed for bidirectional iterators.
template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::bidirectional_iterator_tag) {
	(void)first;
	(void)last;
}

// Performs validity check for random access iterators.
// Throws an exception if the first iterator is greater than the last iterator.
template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::random_access_iterator_tag) {
	if (first > last) {
		throw std::length_error("cannot create std::vector larger than max_size()");
	}
}

// No validity checks are performed for input iterators (std:: implementation).
template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::input_iterator_tag) {
	(void)first;
	(void)last;
}

// No validity checks are performed for output iterators (std:: implementation).
template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::output_iterator_tag) {
	(void)first;
	(void)last;
}

// No validity checks are performed for forward iterators (std:: implementation).
template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::forward_iterator_tag) {
	(void)first;
	(void)last;
}

// No validity checks are performed for bidirectional iterators (std:: implementation).
template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::bidirectional_iterator_tag) {
	(void)first;
	(void)last;
}

// Performs validity check for random access iterators (std:: implementation).
// Throws an exception if the first iterator is greater than the last iterator.
template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::random_access_iterator_tag) {
	if (first > last) {
		throw std::length_error("cannot create std::vector larger than max_size()");
	}
}

/** 
 * check_range - Checks the range validity.
 *
 * This function template is used to check the range validity based on the iterator category.
 * It calls the appropriate iterator_validity function based on the iterator category inferred
 * from the iterator traits. The function helps ensure that the range is valid before performing
 * any operations on it.
 *
 * @param first - The first iterator of the range.
 * @param last - The last iterator of the range.
 * @tparam Iter - The type of the iterators.
 */
template <class Iter>
void check_range(Iter first, Iter last) {
	// Calls the appropriate iterator_validity function based on the iterator category inferred from iterator traits.
	iterator_validity(first, last, typename ft::iterator_traits<Iter>::iterator_category());
}

}    // namespace ft

#endif    // ITERATOR_VALIDITY_HPP
