/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:56:54 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/04 21:02:35 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

/*
** @brief Return true if the range [first1, last1) compares
** lexicographically less than the range [first2, last2).
**
** @param first1, last1 the start and the end of the first range.
** @param first2, last2 the start and the end of the second range.
** @param comp the function that will compare.
** Two elements, a and b are considered equivalent 
** if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a)).
** compares strings letter by letter
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
