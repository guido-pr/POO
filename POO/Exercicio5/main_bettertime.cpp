#include <iostream>
#include "MyTime.hpp"
#include "MyBetterTime.hpp"
#include "MyTime.cpp"
#include "MyBetterTime.cpp"

int main() {
    // ===== Testes com MyTime =====
    MyTime t1(10, 45);
    MyTime t2(5, 30);
    MyTime t3 = t1 + t2;

    std::cout << "MyTime t1: " << t1 << std::endl;
    std::cout << "MyTime t2: " << t2 << std::endl;
    std::cout << "MyTime t1 + t2: " << t3 << std::endl;

    // ===== Testes com MyBetterTime =====
    MyBetterTime bt1(10, 20, 30);
    MyBetterTime bt2("15:45:50");
    MyBetterTime bt3 = bt1 + bt2;

    std::cout << "\nMyBetterTime bt1: " << bt1 << std::endl;
    std::cout << "MyBetterTime bt2: " << bt2 << std::endl;
    std::cout << "MyBetterTime bt1 + bt2: " << bt3 << std::endl;

    // Soma com segundos (int)
    MyBetterTime bt4 = bt1 + 125;  // soma 2 min e 5 seg
    std::cout << "\nMyBetterTime bt1 + 125s: " << bt4 << std::endl;

    // ===== Soma entre tipos diferentes =====
    MyBetterTime bt5 = bt1 + t1;  // bt1 + MyTime
    std::cout << "\nMyBetterTime bt1 + MyTime t1: " << bt5 << std::endl;

    MyBetterTime bt6 = MyBetterTime(t1) + bt2;  // MyTime + bt2
    std::cout << "MyTime t1 + MyBetterTime bt2: " << bt6 << std::endl;

    // ===== Teste com ponteiros =====
    MyTime* ptrT = new MyTime(3, 50);
    MyTime res1 = bt1 + ptrT;
    std::cout << "\nMyBetterTime bt1 + MyTime*(3:50): " << res1 << std::endl;
    delete ptrT;

    MyBetterTime* ptrBT = new MyBetterTime(2, 15, 45);
    MyTime res2 = bt1 + ptrBT;  // ptrBT tratado como MyTime*
    std::cout << "MyBetterTime bt1 + MyBetterTime*(2:15:45) via MyTime*: " << res2 << std::endl;
    delete ptrBT;

    return 0;
}
