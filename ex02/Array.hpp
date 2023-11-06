#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
  private:
    T *_items;
    unsigned int _size;

  public:
    // default constructer
    Array(void) : _items(new T[0]), _size(0) {}

    // parameterized constructer
    Array(unsigned int n) : _items(new T[n]), _size(n) {
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_items[i] = 0;
        }
    }

    // copy constructer
    Array(const Array &src) : _items(new T[src._size]), _size(src._size) {
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_items[i] = src._items[i];
        }
    }

    // destructer
    ~Array(void) { delete[] _items; }

    // assignment overload
    T &operator=(const Array &rhs) {
        if (this != &rhs) {
            delete[] this->_items;

            this->_items = new T[rhs._size];
            this->_size = rhs._size;

            for (unsigned int i = 0; i < this->_size; i++) {
                this->_items[i] = rhs._items[i];
            }
        }
        return *this;
    }

    // subscript overload
    T &operator[](const unsigned int &i) {
        if (i >= _size)
            throw Array::InvalidIndex();
        return this->_items[i];
    }

    // member functions
    const unsigned int &size() const { return _size; }

    // exceptions
    class InvalidIndex : public std::exception {
        virtual const char *what() const throw() {
            return ("index is outside of the array");
        }
    };
};

#endif /* ARRAY_HPP */
