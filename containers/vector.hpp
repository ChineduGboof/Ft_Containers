/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:59:29 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/09 16:29:43 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include <limits>
#include "../tools/type_traits.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/vector_iterator.hpp"
#include "../tools/iterator_validity.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/lexicographical_compare.hpp"

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
    typedef ft::reverse_iterator<iterator>              reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
    typedef typename allocator_type::difference_type    difference_type;
    typedef typename allocator_type::size_type          size_type;

    /*
    ** Member Functions
    */
    /************************ DEFAULT CONSTRUCTOR ************************/
    /**
     *  Constructor: Constructs an empty vector.
        Description: Initializes the vector with default values for all members.
    */
    explicit vector (const allocator_type& alloc = allocator_type()):   _data(0), _alloc(alloc), _size(0), _capacity(0) {}

    /************************ FILL CONSTRUCTOR  ************************/
    /**
     * Fill Constructor: Constructs a vector with n copies of val.
        Description: Allocates memory for n elements, constructs n copies of val, 
        and initializes the vector with these values.
    */
    explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()):  _data(0), _alloc(alloc), _size(n), _capacity(n) {
            if (n > 0) {
                _data = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++) {
                    _alloc.construct(_data + i, val);
                }
            }
    }

    /************************ RANGE CONSTRUCTOR ************************/
    /**
     *  Range Constructor: Constructs a vector with elements from the range [first, last).
        Description: Determines the range size, allocates memory for the elements, 
        and constructs the vector by copying the elements from the range.
        Additional Note: The enable_if is used to enable/disable this constructor 
        based on the type of the iterator. It ensures that this constructor is only 
        available if the iterator is not of integral type (!ft::is_integral<Iterator>::value).
        This is important to avoid ambiguity when the constructor could be mistakenly 
        called with integral types, which might have unintended consequences.
        The SFINAE (Substitution Failure Is Not An Error) concept is used in the range constructor 
        to enable or disable the constructor based on the type of the iterator.
    */
    template <class Iterator>
    vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) : _data(0), _alloc(alloc), _size(0), _capacity(0) {
        ft::check_range(first, last);
        difference_type range = 0;
        for (Iterator temp = first; temp != last; temp++) {
            range++;
        }

        _size = _capacity = static_cast<size_type>(range);
        _data = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; i++) {
            _alloc.construct(_data + i, *first++);
        }
    }

    /************************ COPY CONSTRUCTOR ************************/
    /**
     *  Copy Constructor: Constructs a vector by copying another vector.
        Description: Initializes the vector by copying the elements and allocator from vector x.
    */
    vector(const vector& x) : _data(0), _alloc(x._alloc), _size(0), _capacity(0) {
        *this = x;
    }

    /************************ ASSIGNMENT OPERATOR ************************/
    /**
     *  @brief
     *  Assignment Operator: Assigns the contents of one vector to another.
        Return value: Reference to the vector after assignment.
        Description: Deallocates the existing memory, if any, and copies the elements and allocator from vector x.
    */
    vector &operator=(const vector &x) {
        if (!this->empty()) {
            this->~vector();
        }
        
        if (this != &x) {
            _data = _alloc.allocate(x._capacity);
            _size = x._size;
            _capacity = x._capacity;
            for (size_type i = 0; i < _size; i++) {
                _alloc.construct(_data + i, *(x._data + i));
            }
        }
        return *this;
    }

    /************************ DESTRUCTOR ************************/
    /**
     *  @brief
        Destructor: Destroys the vector and frees allocated memory.
        Return value: None.
        Description: Calls the clear function to remove all elements, 
        deallocates the memory, and sets the capacity to 0.
    */
    ~vector() {
        this->clear();
        _alloc.deallocate(_data, _capacity);
        _capacity = 0;
    }

    /************************ ITERATORS ************************/
    
    /**
    * @return The iterator to the first element.
    * explicitly typecast the return value
    */
   	iterator begin() { 
        return iterator(_data); 
    }
    
    const_iterator begin()const { 
        return const_iterator(_data); 
    }

    /**
    ** @return The iterator to the past-the-end element or begin if
    ** the container is empty.
    */
    iterator end() { 
        return iterator(_data + _size); 
    }

    const_iterator end()const { 
        return const_iterator(_data + _size); 
    }
    
    /**
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

    /**
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

    /**
    ** @brief Returns the number of elements stored in the container.
    ** It's not necessarily equal to the storage capacity
    */
    size_type size() const {
        return _size;
    }

    /**
    ** @brief Returns the maximum potential number of elements the the
    ** vector can hold.
    ** will fail on char
    */
    size_type max_size() const {
        return _alloc.max_size();
    }

    /**
    ** @brief Return size of allocated storage capacity.
    ** The number elements it can hold.
    */
    size_type capacity() const {
        return _capacity;
    }

    /**
    ** @brief Returns whether the container is empty.
    ** @return true if the container size is 0, false otherwise.
    */
    bool empty() const {
        return _size == 0;
    }

    /**
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

    /**
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
    
    /**
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

    /**
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
    
    /**
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

    /**
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

    /**
    ** Range (1)
    ** The new contents are elements constructed from each of the elements 
    ** in the range between first and last, in the same order.
    ** @param first the first element in the range.
    ** @param last the last element in the range.
    ** enable this function if it is not integral else use the next assign function
    ** type* = 0 construct is used to conditionally enable or disable the function based on the type trait check
    ** reserve more space if the range is larger than current capacity, then update the values
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

    /**
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

    /*
    ** @brief Adds a new element at the end of the vector after its current last element.
    ** The content of "val" is copied (moved) to the new element.
    ** @param val The value to be copied.
    ** This effectively increases the container size by one, 
    ** which causes an automatic reallocation of the allocated storage space 
    ** if -and only if- the new vector size surpasses the current vector capacity.
    */
    void push_back (const value_type& val) {
        if (!_capacity)
            this->reserve(1);
        else if (_size == _capacity)
            this->reserve(_capacity * 2);
        _alloc.construct(_data + _size, val);
        _size++;
    }

    /**
    ** @brief Delete the last element of the container.
    ** Reduce the size of the vector of one.
    ** If the container is empty, cause undefined behavior.
    */
    void pop_back() {
        _alloc.destroy(&_data[_size - 1]);
        _size--;
    }

    /**
    ** Single Element
    ** @brief Insert an element at the position. Can increase the size
    ** of the container. This action forces the container to
    ** realocate all the elements that were after "postion"
    ** to their new positions.
    **
    ** @param position The position where insert.
    ** @param val The element to insert.
    ** @return An iterator that points to the first of the newly inserted elements.
    */
    iterator insert (iterator position, const value_type& val){
        difference_type difference = position - this->begin();
        if (difference >= 0) {
            if (!_capacity)
                this->reserve(1);
            else if (_size == _capacity) {
                this->reserve(_capacity * 2);
            }

            for (size_type i = _size; i > static_cast<size_type>(difference); i--) {
                _alloc.construct(_data + i, *(_data + i - 1));
                _alloc.destroy(_data + i - 1);
            }
            _alloc.construct(_data + (size_type)difference, val);
        }
        _size++;
        return position;
    }

    /**
    ** Fill Insert
    ** @brief Insert an element a "n" amount of times
    ** starting from the specified position. Can increase the capacity
    ** of the container. This action force the container to
    ** realocate all the elements that were after "position"
    ** to their new positions.
    ** vec.insert(<start location>, <size>, <value>)
    ** @param position The position where insert.
    ** @param n Amout of element to insert.
    ** @param val The element to insert.
    ** 
    */

    void insert(iterator position, size_type n, const value_type& val) {
    difference_type difference = position - this->begin();
    size_type new_size = _size + n;
    if (new_size > _capacity) {
        this->reserve(std::max(_capacity * 2, new_size));
    }

    if (n > 0){
        pointer insert_pos = _data + difference;

        // Shift existing elements to make space for the new elements
        if (difference < static_cast<difference_type>(_size)) {
            // Move elements from the insert position onwards
            for (pointer it = _data + _size - 1; it >= insert_pos; --it) {
                _alloc.construct(it + n, *it);
                _alloc.destroy(it);
            }
        }
        // Construct new elements at the insert position
        for (size_type i = 0; i < n; ++i) {
            _alloc.construct(insert_pos + i, val);
        }

        _size = new_size;
    }
}

    /**
    ** @brief Insert element in range from ["first" to
    ** "last") at "position". Can increase the capacity of
    ** the container. Throw if the iterator given is not valid.
    ** Reallocate all elements after the dist between first and last.
    ** vec.insert(<start location>, <pointer to start of array>, <pointer to end of array>)
    ** @param position the position where insert.
    ** @param first the first element in the range.
    ** @param last the last element in the range.
    ** 1, 2, 3, 4 -> 1, 2, 3, 6, 7, 5
    ** diff(3) | n (2) | new_size = (6)
    ** i = 0; i < 3; i++; {1, 2, 3, ?, ?, ?} -> copy old values to temp_data
    ** i = 3; i < 6; i++; {1, 2, 3, 6, 7, ?} -> copy new values to temp
    ** i = 5, i < 6; i++; {1, 2, 3, 6, 7, 4} -> copy the last old value to temp
    */
    template <class Iterator>
    void insert(iterator position, Iterator first, Iterator last,
                typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) {
        difference_type difference = position - this->begin();
        size_type n = 0;
        Iterator it = first;

        while (it != last) { ++n; ++it; }
        
        size_type new_size = _size + n;
        if (new_size > _capacity) {
            this->reserve(std::max(_capacity * 2, new_size));
        }
        pointer temp_data = _alloc.allocate(new_size);
        // Copy elements before the insert position
        for (size_type i = 0; i < static_cast<size_type>(difference); i++) {
            _alloc.construct(temp_data + i, *(_data + i));
        }
        // Copy inserted elements
        it = first;
        for (size_type i = static_cast<size_type>(difference); i < static_cast<size_type>(difference) + n; i++) {
            _alloc.construct(temp_data + i, *it++);
        }
        // Copy elements after the insert position
        for (size_type i = static_cast<size_type>(difference) + n; i < new_size; i++) {
            _alloc.construct(temp_data + i, *(_data + i - n));
        }
        // Destroy old elements
        for (size_type i = 0; i < _size; i++) {
            _alloc.destroy(_data + i);
        }
        _alloc.deallocate(_data, _capacity);
        _data = temp_data;
        _size = new_size;
    }

    /**
    ** @brief Remove element from the vector at "position".
    ** Reduce the size of 1;
    ** @param position the iterator pointing to the
    ** element to remove.
    ** @return a pointer to the element a "&(*position) + 1"; 
    ** An iterator pointing to the new location of the element 
    ** that followed the last element erased by the function call. 
    ** This is the container end if the operation erased the last element in the sequence.
    ** {1, 2, 3, 4} -> {1, 2, 4}
    */

    iterator erase(iterator position) {
        for (iterator it = position; it != this->end() - 1; it++) {
            *it = *(it + 1);
        }
        _alloc.destroy(_data + _size - 1);
        _size--;
        return position;
    }

    /**
    ** @brief Remove element from the vector a range of element.
    ** Reduce the size by the number of element removed.
    ** @param first the first element in the range.
    ** @param last the last element in the range.
    ** @return An iterator that point to the first element
    ** after "last".
    ** {1, 2, 3, 4, 5, 6} -> {1, 2, 6}
    ** first = 3 last = 6 begin = 1, end = null
    */

    iterator erase(iterator first, iterator last) {
        iterator result = first;
        for (iterator it = last; it != this->end(); ++it, ++first) {
            *first = *it;
        }
        iterator end_val = this->end();
        while (first != end_val) {
            _alloc.destroy(_data + (_size - 1));
            --_size;
            ++first;
        }
        return result;
    }

    /**
    ** @brief Exchanges the content of the container 
    ** by the content of x, which is another vector object 
    ** of the same type. Sizes may differ.
    ** All iterators, references, pointer on the swaped
    ** objects stay valid.
    ** foo(3, 100), bar(5, 200) -> foo(5, 200), bar(3, 100)
    ** @param x the vector to swap.
    */
    void swap(vector& x) {
        pointer temp_data = _data;
        allocator_type temp_alloc = _alloc;
        size_type temp_size = _size;
        size_type temp_capacity = _capacity;

        _data = x._data;
        _alloc = x._alloc;
        _size = x._size;
        _capacity = x._capacity;

        x._data = temp_data;
        x._alloc = temp_alloc;
        x._size = temp_size;
        x._capacity = temp_capacity;
    }

    /**
    ** @brief Removes (destroy) all elements from the
    ** container. Final size is 0.
    */
    void clear() {
        for (size_type i = 0; i < _size; i++) {
            _alloc.destroy(_data + i);
        }
        _size = 0;
    }

    /************************ ALLOCATOR ************************/
    /**
    ** @brief Returns a copy of the allocator object
    ** associated with the vector.
    */
    allocator_type get_allocator() const {
        return _alloc;
    }


private:
    pointer           _data;
    allocator_type    _alloc;
    size_type         _size;
    size_type         _capacity;
};

/************************ NON-MEMBER FUNCTIONS ************************/
/*
** the operator== implementation you provided checks both the sizes 
** and the values of the elements in the vectors for equality.
*/

template <class T, class Allocator>
bool operator==(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}

	for (size_t i = 0; i < lhs.size(); i++) {
		if (lhs.at(i) != rhs.at(i)) {
			return false;
		}
	}
	return true;
}

/*
** The operator!= simply returns the negation of the operator==
*/
template <class T, class Allocator>
bool operator!=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return !(lhs == rhs);
}

/**
** @brief Compare vector container to know
** if "lhs" elements are lexicographicalement less than "rhs".
**
** @param lhs vector to compare with "rhs".
** @param rhs vector for comparison of "lhs".
** @return true if "lhs" is lexicographicalement less, false otherwise.
*/
template <class T, class Allocator>
bool operator<(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}


template <class T, class Allocator>
bool operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return !(rhs < lhs);
}


template <class T, class Allocator>
bool operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return rhs < lhs;
}

template <class T, class Allocator>
bool operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return !(lhs < rhs);
}

/**
** @brief Overload of swap (vector).
** The contents of container are swaped.
** @param x, y the containers to swap.
*/
template <class T, class Allocator>
void swap(ft::vector<T, Allocator> &lhs, ft::vector<T, Allocator> &rhs) {
	lhs.swap(rhs);
}
  
}   //namespace

#endif