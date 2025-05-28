#ifndef RELATORIO_ERRO_HPP
#define RELATORIO_ERRO_HPP

#include <string>
#include "MyDate.hpp"

class RelatorioErro {
private:
    int CodigoErro;
    std::string MsgErro;
    const MyDate DataErro;
    
    static int NumeroErros;
    static const std::string NOME_ARQUIVO_LOG;
    
    void salvarNoLog();

public:
    RelatorioErro(int codigo, const std::string& mensagem, const MyDate& data);
    ~RelatorioErro();
    
    static int getNumeroErros();
};

#endif