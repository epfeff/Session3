#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP
#include <cassert>
#include <iostream> // for debugging
#include <iterator> // for iterator category tags

/*
Forward & bidirectional iterators requirements:

Iterator:
- OK - CopyConstructible
- OK - CopyAssignable
- OK - Destructible
- OK - Supports: *a (Dereferenceable)
- OK - Supports: ++a (Preincrementable)

Input Iterator:
- All requirements of an iterator.
- OK - Supports: == (EqualityComparable)
- OK - Supports: !=
- OK - Supports: ->
- OK - Supports: a++ (Postincrementable)

Forward Iterator:
- All requirements of an input iterator
- OK - DefaultConstructible
- OK - Supports expression: *a++

Bidirectional Iterator:
- All requirements of a forward iterator
- OK - Predecrementable
- OK - Postdecrementable
- OK -Supports expression: *a--

*/

// my iterator
template <typename T>
class FwdIterator {
  public:
    typedef T value_type; // these names are dictated by e.g. the InputIterator concept
    typedef T& reference; // same here, reference_t or reference_type is "wrong"

    // constructor
    FwdIterator(T* pcurrent, T* pstart, T* pend);
    // copy constructor
    FwdIterator(FwdIterator const&) = default;
    // copy assignement
    FwdIterator& operator=(FwdIterator const&) = default;
    // destructor
    ~FwdIterator() {};
    // Iterator
    // postfix increment operator
    FwdIterator operator++(int);
    // prefix increment operator
    FwdIterator& operator++();
    // postfix decrement operator
    FwdIterator operator--(int);
    // prefix decrement operator
    FwdIterator& operator--();
    // not equal != operator
    bool operator!=(FwdIterator arg);
    // equal == operator
    bool operator==(FwdIterator arg);
    // arrow operator (pointer)
    FwdIterator* operator->();
    // dereference operator
    reference operator*() const {
      return *current;
    }


  private:
    // private data members
    T* current;  // current position pointer
    T* start; // pointer to beginning
    T* end;   // pointer to "one past" the end

    // checks if the current pos. if smaller or equal to the end of the array
    // end if the current pos. is greater or equal to the end of the array.
    bool check() {
      bool ok;
      ok = (current >= start) && (current <= end);
      return ok;
    }
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
  assert(check());
  FwdIterator temp = *this; // copy of the current position in the array
  current = current +1;
  return temp;
}
// prefix ++ operator function
template <typename T>
FwdIterator<T>& FwdIterator<T>:: operator++() {
  assert(check());
  ++current;
  return *this;
}
// postfix -- operator function
template <typename T>
FwdIterator<T> FwdIterator<T>:: operator--(int) {
  assert(check());
  FwdIterator temp = *this; // copy of the current position in the array
  current = current -1;
  return temp;
}
// prefix -- operator function
template <typename T>
FwdIterator<T>& FwdIterator<T>:: operator--() {
  assert(check());
  current = current - 1;
  return *this;
}
// unequality operator function
template <typename T>
bool FwdIterator<T>::operator!=(FwdIterator arg) {
  assert(check());
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
  assert(check());
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
// arrow operator
template <typename T>
FwdIterator<T>* FwdIterator<T>:: operator->() {
  assert(check());
  return current;
}


#endif /* MY_ITERATOR_HPP */
