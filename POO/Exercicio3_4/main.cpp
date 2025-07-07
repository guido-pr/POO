#include "MyDate.hpp"
#include "MyDate.cpp"
#include "RelatorioErro.hpp"
#include "RelatorioErro.cpp"
#include <iostream>

int main() {
    try {
        // Criar uma data válida
        MyDate date("2023-10-15");
        date.SetFormatoLongo(false);
        std::cout << "Data inicial (curta): " << date << std::endl;

        // Alterar para outra data válida
        date.SetDate("2024-02-29");
        std::cout << "Data alterada (curta): " << date << std::endl;

        // Testar formato longo
        date.SetFormatoLongo(true);
        std::cout << "Data no formato longo: " << date << std::endl;

        // Testar formato curto novamente
        date.SetFormatoLongo(false);
        std::cout << "Data no formato curto: " << date << std::endl;

        // Testar uma data inválida
        date.SetDate("2023-15-99"); // Mês e dia inválidos
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    try {
        // Testar outro caso de erro: formato inválido
        MyDate invalidDate("01-01-2000");  // Data com formato errado
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    try {
        // Criar uma data válida
        MyDate date1("2023-10-01");
        std::cout << "Data 1 (curta): " << date1 << std::endl;

        // Somar dois objetos MyDate (soma de dias, meses e anos)
        MyDate date2("2024-02-03");
        std::cout << "Data 2 (curta): " << date2 << std::endl;
        
        MyDate result = date1 + date2; 
        std::cout << "Soma de duas datas: " << result << std::endl;

        // Somar um inteiro (dias) a uma data
        int diasParaAdicionar = 3;
        MyDate result2 = date1 + diasParaAdicionar; 
        std::cout << "Data apos adicionar " << diasParaAdicionar << " dias: " << result2 << std::endl;

        // Testar somar um número negativo de dias (retroceder no tempo)
        int diasNegativos = -45;
        MyDate result3 = date1 + diasNegativos;
        std::cout << "Data após subtrair " << -diasNegativos << " dias: " << result3 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    MyDate dataAtual("2023-11-15");  // Usando sua classe MyDate
    
    {
        RelatorioErro erro1(404, "Arquivo não encontrado", dataAtual);
        std::cout << "Erros ativos: " << RelatorioErro::getNumeroErros() << std::endl;
        
        {
            RelatorioErro erro2(500, "Erro interno do servidor", dataAtual);
            std::cout << "Erros ativos: " << RelatorioErro::getNumeroErros() << std::endl;
        }  // erro2 é destruído aqui e salvo no log
        
        std::cout << "Erros ativos: " << RelatorioErro::getNumeroErros() << std::endl;
    }  // erro1 é destruído aqui e salvo no log

    return 0;
}