#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP
#include <cassert>
#include <iostream> // for debugging
#include <iterator> // for iterator category tags

/*
Forward & bidirectional iterators requirements:

Iterator:
- CopyConstructible
- CopyAssignable
- Destructible
- Supports: *a (Dereferenceable)
- Supports: ++a (Preincrementable)

Input Iterator:
- All requirements of an iterator.
- Supports: == (EqualityComparable)
- Supports: !=
- Supports: ->
- Supports: a++ (Postincrementable)

Forward Iterator:
- All requirements of an input iterator
- DefaultConstructible
- Supports expression: *a++

Bidirectional Iterator:
- All requirements of a forward iterator
- Predecrementable
- Postdecrementable
- Supports expression: *a--

*/

// my iterator
template <typename T>
class FwdIterator {
  public:
    typedef T value_type; // these names are dictated by e.g. the InputIterator concept
    typedef T& reference; // same here, reference_t or reference_type is "wrong"

      // constructor
    FwdIterator(T* pcurrent, T* pstart, T* pend);

    // Iterator
    // postfix increment operator
    FwdIterator operator++(int);
    // prefix increment operator
    FwdIterator& operator++();
    // prefix decrement operator
    FwdIterator& operator--();
    // not equal != operator
    bool operator!=(FwdIterator arg);
    // equal == operator
    bool operator==(FwdIterator arg);
    // dereference operator
    reference operator*() const {
      return *current;
    }


  private:
    // private data members
    T* current;  // current position pointer
    T* start; // pointer to beginning
    T* end;   // pointer to "one past" the end
};

// FwdIterator constructor function
template <typename T>
FwdIterator<T>::FwdIterator(T* pcurrent, T* pstart, T* pend)
{
  current = pcurrent;
  start = pstart;
  end = pend;
}
// postfix ++ operator function
template <typename T>
FwdIterator<T> FwdIterator<T>:: operator++(int) {
  FwdIterator temp = *this; // copy of the current position in the array 
  current = current +1;
  return temp;
}
// prefix ++ operator function
template <typename T>
FwdIterator<T>& FwdIterator<T>:: operator++() {
  ++current;
  return *this;
}
// prefix -- operator function
template <typename T>
FwdIterator<T>& FwdIterator<T>:: operator--() {
  current = current - 1;
  return *this;
}
// unequality operator function
template <typename T>
bool FwdIterator<T>::operator!=(FwdIterator arg) {
  if(*this == arg)
  {
    return false;
  } else {
    return true;
  }
}
// equality operator function
template <typename T>
bool FwdIterator<T>::operator==(FwdIterator arg) {
  bool a = false;
  if (start == arg.start) {
    if (end == arg.end){
      if (current == arg.current) {
        a = true;
      }
    }
  }
  return a;
}
#endif /* MY_ITERATOR_HPP */
