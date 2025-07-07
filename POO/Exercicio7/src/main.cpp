#include <iostream>
#include "OrderedDateTime.hpp"

int main() {
    OrderedDateTime dt1(7, 7, 2024, 15, 30, 0);
    OrderedDateTime dt2(1, 1, 2025, 0, 0, 0);
    OrderedDateTime dt3(7, 7, 2024, 15, 30, 0);

    if (dt1 < dt2) {
        std::cout << "dt1 é anterior a dt2\n";
    } else {
        std::cout << "dt1 NÃO é anterior a dt2\n";
    }

    if (dt1 < dt3) {
        std::cout << "dt1 é anterior a dt3\n";
    } else {
        std::cout << "dt1 NÃO é anterior a dt3\n";
    }

    return 0;
}