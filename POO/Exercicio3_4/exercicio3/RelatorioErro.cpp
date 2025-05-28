#include "RelatorioErro.hpp"
#include <fstream>
#include <iostream>

// Inicialização dos membros estáticos
int RelatorioErro::NumeroErros = 0;
const std::string RelatorioErro::NOME_ARQUIVO_LOG = "erros.log";

// Implementação do construtor
RelatorioErro::RelatorioErro(int codigo, const std::string& mensagem, const MyDate& data)
    : CodigoErro(codigo), MsgErro(mensagem), DataErro(data) {
    NumeroErros++;
}

// Implementação do destrutor
RelatorioErro::~RelatorioErro() {
    NumeroErros--;
    salvarNoLog();
}

// Implementação do método para salvar no log
void RelatorioErro::salvarNoLog() {
    std::ofstream arquivo(NOME_ARQUIVO_LOG, std::ios::app);
    
    if (arquivo.is_open()) {
        arquivo << "ERRO [" << CodigoErro << "] em " << DataErro << ": " << MsgErro << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir arquivo de log!" << std::endl;
    }
}

// Implementação do método estático
int RelatorioErro::getNumeroErros() {
    return NumeroErros;
}