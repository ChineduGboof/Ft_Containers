/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:50:22 by gboof             #+#    #+#             */
/*   Updated: 2023/05/12 08:28:10 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
// #include <memory>


namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {
    public:
    T                                                   value_type;
    Alloc                                               allocator_type;
    allocator_type::reference                           reference;
    allocator_type::const_reference                     const_reference;
    allocator_type::pointer                             pointer;
    
    explicit vector (const allocator_type& alloc = allocator_type()){}
    
    explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()){}

    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

    vector (const vector& x){}
};
  
}   //namespace


#endif