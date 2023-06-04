/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:56:31 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/04 21:02:00 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft {

    /*
        Iterators are classified into five categories depending on the functionality they implement:
    */

    // 1. Empty class to identify the category of an iterator as an input iterator:
    struct input_iterator_tag {};

    // 2. Empty class to identify the category of an iterator as an output iterator:
    struct output_iterator_tag {};

    // 3. Forward iterators have all the functionality of input iterators
    struct forward_iterator_tag : public input_iterator_tag {};

    // 4. Bidirectional iterators are like forward iterators but can also be iterated through backwards
    struct bidirectional_iterator_tag : public forward_iterator_tag {};

    // 5. Random-access iterators implement all the functionality of bidirectional iterators,
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};


    // Iterator traits class template

    // Primary template for generic iterator types
    template <class Iterator>
    struct iterator_traits {
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    // Partial specialization for pointer types
    template <class T>
    struct iterator_traits<T*> {
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    // Partial specialization for const pointer types
    template <class T>
    struct iterator_traits<const T*> {
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    // Iterator base class template
    template <class Category, class T, class Distance = std::ptrdiff_t,
            class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T               value_type;
        typedef Distance        difference_type;
        typedef Pointer         pointer;
        typedef Reference       reference;
        typedef Category        iterator_category;
    };

}   // namespace ft

#endif // !ITERATOR_TRAITS_HPP
