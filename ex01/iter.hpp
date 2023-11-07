#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *arr, std::size_t size, void (*fn)(const T &)) {
    if (arr == NULL || fn == NULL)
        return;

    for (std::size_t i = 0; i < size; i++)
        fn(arr[i]);
}

template <typename T>
void log(const T &item) {
    std::cout << item << std::endl;
}

#endif /* ITER_HPP */
