#include "MyDateTime.hpp"
#include "MyDate.hpp"
#include "MyDateTime.cpp"
#include "MyDate.cpp"
#include "MyTime.hpp"
#include "MyBetterTime.hpp"
#include "MyTime.cpp"
#include "MyBetterTime.cpp"
#include <iostream>

int main() {
    try {
        // Teste de construção
        MyDateTime dt1(15, 5, 2023, 14, 30, 45);
        MyDateTime dt2("2023-06-20 18:45:30");
        
        // Teste de saída
        std::cout << "dt1: " << dt1 << std::endl;
        std::cout << "dt2: " << dt2 << std::endl;
        
        // Teste de função DateTime()
        std::cout << "dt1.DateTime(): " << dt1.DateTime() << std::endl;
        
        // Teste de upcasting
        MyDate& dateRef = dt1;
        std::cout << "Como MyDate: " << dateRef << std::endl;
        
        MyBetterTime& timeRef = dt1;
        std::cout << "Como MyBetterTime: " << timeRef << std::endl;
        
        // Teste de operador de soma (herdado de MyDate)
        MyDateTime dt3 = dt1 + dt2;
        std::cout << "dt1 + dt2: " << dt3 << std::endl;
        
        MyDateTime dt4 = dt1 + 5; // adiciona 5 dias
        std::cout << "dt1 + 5 dias: " << dt4 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    
    return 0;
}