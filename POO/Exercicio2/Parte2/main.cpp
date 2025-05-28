#include "MyDate.hpp"
#include "MyDate.cpp"
#include <iostream>

int main() {
try {
    // Criar uma data válida
    MyDate date("2023-10-15");
    std::cout << "Data inicial: " << date.Date() << std::endl;

    // Alterar para outra data válida
    date.SetDate("2024-02-29");
    std::cout << "Data alterada: " << date.Date() << std::endl;

    // Testar uma data inválida
    date.SetDate("2023-15-99"); // Mês e dia inválidos
} catch (const std::exception& e) {
    std::cerr << "Erro: " << e.what() << std::endl;
}

try {
    // Testar outro caso de erro: formato inválido
    MyDate invalidDate("01-01-2000");
} catch (const std::exception& e) {
    std::cerr << "Erro: " << e.what() << std::endl;
}

return 0;
}