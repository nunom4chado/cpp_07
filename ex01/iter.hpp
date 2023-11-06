#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, std::size_t size, void (*fn)(const T &)) {
    for (std::size_t i = 0; i < size; i++)
        fn(arr[i]);
}

template <typename T>
void log(T &item) {
    std::cout << item << std::endl;
}

#endif /* ITER_HPP */
