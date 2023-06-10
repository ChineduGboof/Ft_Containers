/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:56:54 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/10 19:14:58 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

/**
 * @brief Return true if the range [first1, last1) compares lexicographically less than the range [first2, last2).
 *
 * @param first1, last1 The iterators defining the range of the first sequence.
 * @param first2, last2 The iterators defining the range of the second sequence.
 * @param comp The comparison function used to compare the elements.
 * @return True if the first range compares lexicographically less than the second range, false otherwise.
 * @details The lexicographical comparison compares two sequences element by element until the end of either sequence is reached.
 *          It returns true if the first sequence compares lexicographically less than the second sequence.
 *          If an element in the first sequence is less than the corresponding element in the second sequence, true is returned.
 *          If an element in the second sequence is less than the corresponding element in the first sequence, false is returned.
 *          If the first sequence is a prefix of the second sequence, true is returned.
 *          If the second sequence is a prefix of the first sequence, false is returned.
 *          The comparison is performed using the provided comparison function 'comp'.
 *          The elements are considered equivalent if 'comp(a, b) == false' and 'comp(b, a) == false'.
 * The comparison is performed letter by letter, character by character, similar to comparing strings in a dictionary.
 */
namespace ft {

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, InputIterator2 last2)
{
  while (first1 != last1)
  {
    if (first2 == last2 || *first2 < *first1)
      return false;
    else if (*first1 < *first2)
      return true;
    ++first1;
    ++first2;
  }
  return (first2 != last2);
}

}    // namespace ft

#endif    // LEXICOGRAPHICAL_COMPARE_HPP
