#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <utility> // for std::swap
#include <cassert>
#include "iterator.hpp"

template <class T>
class Array {

public:
    using size_type = std::size_t ;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    // define iterator typedef (using)
    using iterator = FwdIterator<T>;

    Array(); // empty array
    Array(const size_type &, const value_type & = value_type() ); // Array of given size
    Array(const Array<T> &); // copy of an Array
    ~Array();

    Array<T> & operator= (Array<T>); // assign another array

    size_type size() const;  // the size of the array
    void resize(const size_type &); // change the size of the array

    reference operator[](const size_type & index);
    const_reference operator[](const size_type & index) const;

    void swap(Array<T> & x);

    // declare begin and end
    iterator begin();
    iterator end();

private:
    size_type sz_; // size
    value_type* v_;   // pointer to the actual array
};


// structors
template <class T>
Array<T>::Array(): sz_(0), v_(0) {}

template <class T>
Array<T>::Array( const size_type & s
               , const value_type & initial): sz_(s)
                                            , v_(new value_type[sz_]) {
    for ( size_type i = 0; i < sz_; ++i )
        v_[i] = initial;

}

template <class T>
Array<T>::Array(const Array<T> & rhs): sz_(rhs.sz_)
                                     , v_(new value_type[sz_]) {
    for ( size_type i = 0; i < sz_ ; ++i )
        v_[i] = rhs.v_[i];
}

template <class T>
Array<T>::~Array() {
    delete[] v_;
}


template <class T>
void Array<T>::swap(Array<T>& rhs) {
    std::swap( sz_, rhs.sz_ );
    std::swap( v_, rhs.v_ );
}


// the best version: pass by value so that a copy is already created, then swap
template <class T>
Array<T>& Array<T>::operator= (Array<T> rhs)
{
    // copy and swap trick
    swap(rhs);
    return *this;
}


template <class T>
typename Array<T>::size_type Array<T>::size() const {
    return sz_;
}

// elegant implementation using swap
template <class T>
void Array<T>::resize(const size_type & new_size) {
    Array<T> arr(new_size);
    for( size_type i = 0; i < sz_ and i < new_size; ++i )
        arr.v_[i] = v_[i];
    swap(arr); // think of: this->swap(arr)
}

template <class T>
typename Array<T>::reference Array<T>::operator[](const size_type & index) {
    // only assert and not error here, the version with runtime error is called
    // .at(index) for most containers (errors are expensive)
    assert (index>=0 and index < size());
    return v_[index];
}

template <class T>
typename Array<T>::const_reference Array<T>::operator[](const size_type & index) const {
    // not nice that we have twice the same implementation, can be solved
    // but not in this lecture
    assert (index>=0 and index < size());
    return v_[index];
}

// Begin and End method definitions.

// Begin() method - returns an iterator pointing on the beginning of the container
template <class T>
typename Array<T>::iterator Array<T>::begin() {
  return iterator(v_ , v_ , v_ + sz_);
}
// End() method - retusn an iterator pointing on the end of the container
template <class T>
typename Array<T>::iterator Array<T>::end() {
  return iterator(v_ + sz_ , v_ , v_ + sz_);
}

#endif // ARRAY_HPP
