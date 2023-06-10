/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:38:40 by gboof             #+#    #+#             */
/*   Updated: 2023/06/10 19:18:44 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft {

/**
 * @brief Compares two ranges for equality.
 *
 * @param first1, last1 The iterators defining the range of the first sequence.
 * @param first2 The iterator defining the start of the second sequence.
 * @return True if the elements in the ranges are equal, false otherwise.
 * @details The function compares the elements in the range `[first1, last1)` with the elements starting from `first2`.
 *          It returns true if all the corresponding elements are equal, and false otherwise.
 *          The comparison is performed using the equality operator `==` on the elements.
 *          The function assumes that the second range has enough elements to match the size of the first range.
 *          If the sizes of the ranges are different, the behavior is undefined.
 */

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
    while (first1!=last1) {
        if (!(*first1 == *first2))
            return false;
        ++first1; ++first2;
    }
    return true;
}

}    // namespace ft

#endif    // EQUAL_HPP
