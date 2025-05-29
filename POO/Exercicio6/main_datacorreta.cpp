#include "MyDate.hpp"
#include "MyDate.cpp"
#include <iostream>

int main() {
    try {
        // Teste com data inválida
        MyDate dataInvalida(31, 2, 2023);
    } catch (const std::runtime_error& e) {
        std::cout << "Erro capturado: " << e.what() << std::endl;
    }
    
    // Teste de aproximação
    MyDate dataAproximada = MyDate::DataCorretaAproximada(31, 2, 2023);
    std::cout << "Data aproximada: " << dataAproximada << std::endl;
    
    return 0;
}