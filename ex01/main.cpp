#include "iter.hpp"
#include <iostream>

void times2(const float &n) { std::cout << n * 2 << std::endl; }

int main(void) {
    {
        int a[] = {10, 42, 4, 8};
        iter(a, sizeof(a) / sizeof(int), log);

        std::cout << "------" << std::endl;

        float b[] = {10.12f, 42.1f, 4.87f, 8.4f};
        iter(b, sizeof(b) / sizeof(float), times2);

        std::cout << "------" << std::endl;

        std::string c[] = {"hello", "goodbye"};
        iter(c, sizeof(c) / sizeof(std::string), log);
    }
    return 0;
}