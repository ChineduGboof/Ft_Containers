/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:59:29 by cegbulef          #+#    #+#             */
/*   Updated: 2023/05/24 20:19:18 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"

#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "../tools/type_traits.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/vector_iterator.hpp"
#include "../tools/iterator_validity.hpp"


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
    /************************ DEFAULT CONSTRUCTOR ************************/

    explicit vector (const allocator_type& alloc = allocator_type()):   _data(0),
                                                                        _alloc(alloc),
                                                                        _size(0), 
                                                                        _capacity(0) {
                                                                            std::cout << YELLOW << "vector default constructor called" << std::endl;
                                                                        }

    /************************ FILL CONSTRUCTOR  ************************/
    explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()):    _data(0),
                                                                        _alloc(alloc),
                                                                        _size(n), 
                                                                        _capacity(n) {
            std::cout << "vector fill constructor called" << std::endl;
            if (n > 0)
            {
                _data = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++) {
                    _alloc.construct(_data + i, val);
                }
            }
    }


    // template <class InputIt>
    //     vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()):    _data(0),
    //                                                                                                         _alloc(alloc),
    //                                                                                                         _size(0),
    //                                                                                                         _capacity(0) 
    // {}
    
    // vector(const vector& x){}

    /************************ DESTRUCTOR ************************/
    ~vector(){
        std::cout << "vector destructor called" << std::endl;
    }

    /************************ ITERATORS ************************/
    
    /*
    ** @return The iterator to the first element.
    */
   	iterator begin() { 
        return iterator(_data); 
    }
    
    const_iterator begin()const { 
        return const_iterator(_data); 
    }

    /*
    ** @return The iterator to the past-the-end element or begin if
    ** the container is empty.
    */
    iterator end() { 
        return iterator(_data + _size); 
    }

    const_iterator end()const { 
        return const_iterator(_data + _size); 
    }
    
    /*
    ** @brief Give a reverse iterator pointing to the last element
    ** in the container (this->end() - 1).
    ** @return A reverse Iterator to the reverse beginning of the.
    */
    reverse_iterator rbegin() {
        return reverse_iterator(this->end());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(this->end());
    }

    /*
    ** @brief Give a reverse iterator point to the
    ** theorical element preceding the first element
    ** in the container.
    ** @return the reverse iterator.
    */
    reverse_iterator rend() {
        return reverse_iterator(this->begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(this->begin());
    }
    
    /************************ CAPACITY ************************/

    /*
    ** @brief Returns the number of elements stored in the container.
    ** It's not necessarily equal to the storage capacity
    */
    size_type size() const {
        return _size;
    }

    /*
    ** @brief Returns the maximum potential number of elements the the
    ** vector can hold.
    */
    size_type max_size() const {
        return _alloc.max_size();
    }

    /*
    ** @brief Return size of allocated storage capacity.
    ** The number elements it can hold.
    */
    size_type capacity() const {
        return _capacity;
    }

    /*
    ** @brief Returns whether the container is empty.
    ** @return true if the container size is 0, false otherwise.
    */
    bool empty() const {
        return _size == 0;
    }

    /*
    ** @brief Request that the vector capacity be at least
    ** enougth to contain "n" element.
    ** If n is greater that the actual capacity a reallocation
    ** can be happen, otherwise nothing happen.
    **
    ** @param n the capacity asked.
    */
    void reserve(size_type n) {
        if (n > this->max_size()) {
            throw std::length_error("ft::vector::reserve");
        } else if (_capacity < n) {
            allocator_type temp_alloc;
            pointer temp_data = temp_alloc.allocate(n);

            if (_data) {
                for (size_type i = 0; i < _size; i++) {
                    temp_alloc.construct(temp_data + i, _data[i]);
                    _alloc.destroy(_data + i);
                }
                _alloc.deallocate(_data, _capacity);
            }

            _data = temp_data;
            _capacity = n;
        }
    }

    /*
    ** @brief Resizes the container so that it contain "n"
    ** element. If "n" is smaller than the actual size
    ** the container is reduced to "n" elements 
    ** removing those beyond and destroying them.
    ** If n is greater than the current container size,
    ** the content is expanded by inserting at the end as many 
    ** elements as needed to reach a size of n. If val is specified, 
    ** the new elements are initialized as copies of val, 
    ** otherwise, they are value-initialized.
    ** If n is also greater than the current container capacity, 
    ** an automatic reallocation of the allocated storage space takes place.
    ** this function changes the actual content of 
    ** the container by inserting or erasing elements from it.
    ** @param n the new size of the container.
    ** @param val the element to set.
    ** Insert additional elements if _size < n
    ** Example: _size = 3, n = 7, i = 3 : Iterations: 3 < 7
    ** Destroy excess elements if _size > n
    ** Example: _size = 10, n = 4, i = 10 : Iterations: 10 > 4
    */

    void resize(size_type n, value_type value = value_type()) {
        if (n > this->max_size()) {
            throw std::length_error("ft::vector::resize");
        } else if (n > _capacity) {
            this->reserve(std::max(_capacity * 2, n));
        }

        for (size_type i = _size; i < n; i++) {
            _alloc.construct(_data + i, value);
        }
        
        for (size_type i = _size; i > n; i--) {
            _alloc.destroy(_data + i - 1);
        }
        _size = n;
    }

    /************************ ELEMENT ACCESS ************************/
    
    /*
    ** @brief Returns a reference to the element at
    ** position n in the vector container.
    ** If "n" is out of range that's causes undefined behavior.
    */
    reference operator[](size_type n) {
        return *(_data + n);
    }

    const_reference operator[](size_type n) const {
        return *(_data + n);
    }

    /*
    ** @brief Returns a reference to the element at
    ** position n in the vector container.
    ** The main difference between this function and the
    ** operator "[]" is that the function throw an
    ** std::out_of_range exception if "n" is out of the range of
    ** the container.
    */
    reference at(size_type n) {
        if (n >= _size) {
            throw std::out_of_range("ft::vector::at");
        }
        return *(_data + n);
    }

    const_reference at(size_type n) const {
        if (n >= _size) {
            throw std::out_of_range("ft::vector::at");
        }
        return *(_data + n);
    }
    
    /*
    ** @brief Return a reference to the first element
    ** of the container. Call this on an empty container
    ** cause undefined behavior.
    */
    reference front() {
        return *this->begin();
    }

    const_reference front() const {
        return *this->begin();
    }

    /*
    ** @return The iterator to the past-the-end element or begin if
    ** the container is empty.
    */
    reference back() {
        return *(this->end() - 1);
    }

    const_reference back() const {
        return *(this->end() - 1);
    }

    /*
    ** @return A pointer to the first element in the array used internally by the vector.
    ** Member type value_type is the type of the elements in the container, 
    ** defined in vector as an alias of the first class template parameter (T)
    */
    T* data() {
        return _data;
    }
    
    const T* data() const {
        return _data;
    }

    /************************ MODIFIERS ************************/

    /*
    ** Range (1)
    ** @brief Assigns new contents to the vector, replacing its current
    ** contents, add modifying its size accordingly.
    ** New elements are contruct from each of the elements in that
    ** range, between first and last, in the same order.
    ** @param first the first element in the range.
    ** @param last the last element in the range.
    ** enable this function if it is not integral else use the next assign function
    */
    template <class InputIt>
    void assign(InputIt first, InputIt last,
                typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0) {
        ft::check_range(first, last);
        difference_type range = 0;
        for (InputIt temp = first; temp != last; temp++) {
            range++;
        }

        if (static_cast<size_type>(range) > _capacity) {
            this->reserve(range);
        }
        InputIt iter = first;
        _size = static_cast<size_type>(range);
        for (size_type i = 0; i < _size; i++) {
            _alloc.construct(_data + i, *iter++);
        }
    }

    /*
    ** In the fill version (2), the new contents are n elements, 
    ** each initialized to a copy of val.
    ** @brief Fill assign.
    ** Clear the container, fill it with val "n" times.
    ** According size to "n".
    ** @param "n" the number of element.
    ** @param "val" the value of element.
    */
    void assign(size_type n, const value_type& value) {
        this->clear();
        if (n > 0) {
            if (n > _capacity) {
                this->reserve(n);
            }
            _size = n;
            for (size_type i = 0; i < _size; i++) {
                _alloc.construct(_data + i, value);
            }
        }
    }



private:
    pointer           _data;
    allocator_type    _alloc;
    size_type         _size;
    size_type         _capacity;
};
  
}   //namespace


#endif