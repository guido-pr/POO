#include <iostream>
#include "MyTime.hpp"
#include "MyTime.cpp"
#include "MyBetterTime.hpp"
#include "MyBetterTime.cpp"

int main() {
    MyTime t1(10, 45); // 10:45
    MyTime t2(5, 30);  // 05:30

    // Testando a função Time()
    std::cout << "t1: " << t1.Time() << std::endl;
    std::cout << "t2: " << t2.Time() << std::endl;

    // Testando a soma de dois objetos MyTime
    MyTime t3 = t1 + t2;
    std::cout << "t1 + t2: " << t3 << std::endl;

    // Testando a saída com o operador <<
    std::cout << "t3 usando operador <<: " << t3 << std::endl;

    MyBetterTime t4(10, 45, 30); // 10:45:30
    MyBetterTime t5("05:30:45");  // 05:30:45

    // Testando a soma de dois objetos MyBetterTime
    MyBetterTime t6 = t4 + t5;
    std::cout << "t4 + t5: " << t6 << std::endl;

    // Testando a saída com o operador <<
    std::cout << "t6 usando operador <<: " << t6 << std::endl;

    return 0;
}