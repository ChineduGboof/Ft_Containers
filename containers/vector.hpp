/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:59:29 by cegbulef          #+#    #+#             */
/*   Updated: 2023/05/23 08:08:25 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "../tools/type_traits.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/vector_iterator.hpp"


namespace ft {

template < class T, class Allocator = std::allocator<T> >
class vector {
public:
    /*
    **  Member Types
    */
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef ft::vector_iterator<value_type>             iterator;
    typedef ft::vector_iterator<const value_type>       const_iterator;
    // typedef ft::reverse_iterator<iterator>              reverse_iterator;
    // typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
    typedef typename allocator_type::difference_type    difference_type;
    typedef typename allocator_type::size_type          size_type;

    /*
    ** Member Functions
    */
    /************************ Constructor ************************/

    explicit vector (const allocator_type& alloc = allocator_type()):   _data(0),
                                                                        _alloc(alloc),
                                                                        _size(0), 
                                                                        _capacity(0) {
                                                                            std::cout << "vector default constructor called" << std::endl;
                                                                        }

    explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()):    _data(0),
                                                                        _alloc(alloc),
                                                                        _size(n), 
                                                                        _capacity(n) {
            std::cout << "vector fill constructor 1 called" << std::endl;
            if (n > 0)
            {
                std::cout << "vector fill constructor 2 called" << std::endl;
                _data = alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++){
                    _alloc.construct(_data + i, val);
                }
            }
    }


    // template <class InputIterator>
    //     vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):    _data(0),
    //                                                                                                         _alloc(alloc),
    //                                                                                                         _size(0),
    //                                                                                                         _capacity(0) 
    // {}
    
    vector(const vector& x){}
    /************************ Destructor ************************/
    ~vector(){
        std::cout << "vector destructor called" << std::endl;
    }

private:
    pointer           _data;
    allocator_type    _alloc;
    size_type         _size;
    size_type         _capacity;
};
  
}   //namespace


#endif