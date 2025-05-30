#include <iostream>
#include "MyDate.hpp"
#include "MyTime.hpp"
#include "MyBetterTime.hpp"
#include "MyDateTime.hpp"

int main() {
    try {
        // ===== Testes com MyDate =====
        std::cout << "=== Testes com MyDate ===\n";

        // Teste com data inválida
        try {
            MyDate dataInvalida(31, 2, 2023);
        } catch (const std::runtime_error& e) {
            std::cout << "Erro capturado: " << e.what() << std::endl;
        }

        // Teste de aproximação de data inválida
        MyDate dataAproximada = MyDate::DataCorretaAproximada(31, 2, 2023);
        std::cout << "Data aproximada: " << dataAproximada << std::endl;

        // ===== Testes com MyDateTime =====
        std::cout << "\n=== Testes com MyDateTime ===\n";

        MyDateTime dt1(15, 5, 2023, 14, 30, 45);
        MyDateTime dt2("2023-06-20 18:45:30");

        std::cout << "dt1: " << dt1 << std::endl;
        std::cout << "dt2: " << dt2 << std::endl;
        std::cout << "dt1.DateTime(): " << dt1.DateTime() << std::endl;

        // Upcasting
        MyDate& dateRef = dt1;
        std::cout << "Como MyDate: " << dateRef << std::endl;

        MyBetterTime& timeRef = dt1;
        std::cout << "Como MyBetterTime: " << timeRef << std::endl;

        // Operadores herdados
        MyDateTime dt3 = dt1 + dt2;
        std::cout << "dt1 + dt2: " << dt3 << std::endl;

        MyDateTime dt4 = dt1 + 5; // adiciona 5 dias
        std::cout << "dt1 + 5 dias: " << dt4 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
