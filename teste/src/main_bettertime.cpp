#include <iostream>
#include "MyTime.hpp"
#include "MyBetterTime.hpp"
#include <iostream>

int main() {
    // Criando objetos MyTime
    MyTime t1(2, 30); // Representa 2:30
    MyTime t2(3, 45); // Representa 3:45

    // Criando objetos MyBetterTime
    MyBetterTime bt1(1, 20, 15); // Representa 1:20:15
    MyBetterTime bt2(0, 50, 45); // Representa 0:50:45

    // Exibindo os objetos
    std::cout << "MyTime t1: " << t1 << std::endl;
    std::cout << "MyTime t2: " << t2 << std::endl;
    std::cout << "MyBetterTime bt1: " << bt1 << std::endl;
    std::cout << "MyBetterTime bt2: " << bt2 << std::endl;

    // Soma entre dois objetos MyTime
    MyTime t3 = t1 + t2; // Soma MyTime com MyTime
    std::cout << "Soma de MyTime t1 + t2: " << t3 << std::endl;

    // Soma entre dois objetos MyBetterTime
    MyBetterTime bt3 = bt1 + bt2; // Soma MyBetterTime com MyBetterTime
    std::cout << "Soma de MyBetterTime bt1 + bt2: " << bt3 << std::endl;

    // Soma entre MyBetterTime e MyTime
    MyBetterTime bt4 = bt1 + t1; // Soma MyBetterTime com MyTime
    std::cout << "Soma de MyBetterTime bt1 + MyTime t1: " << bt4 << std::endl;

    // Soma entre MyTime e MyBetterTime
    MyBetterTime bt5 = MyBetterTime(t1) + bt2; // Converte MyTime para MyBetterTime e soma
    std::cout << "Soma de MyTime t1 + MyBetterTime bt2: " << bt5 << std::endl;

    // Soma de MyBetterTime com segundos
    MyBetterTime bt6 = bt1 + 120; // Adiciona 120 segundos a bt1
    std::cout << "Soma de MyBetterTime bt1 + 120 segundos: " << bt6 << std::endl;

    return 0;
}