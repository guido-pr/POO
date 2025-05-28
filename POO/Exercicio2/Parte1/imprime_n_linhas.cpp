#include <iostream>
#include <fstream>
#include <string>

int main() {
 std::string nomeArquivo;
 int n;

 // Solicitar ao usuário o nome do arquivo e o número N
 std::cout << "Digite o nome do arquivo: ";
 std::cin >> nomeArquivo;
 std::cout << "Digite o numero de linhas a serem exibidas (N): ";
 std::cin >> n;

 // Abrir o arquivo
 std::ifstream arquivo(nomeArquivo);

 if (!arquivo.is_open()) {
     std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
     return 1; // Encerrar o programa com código de erro
 }

 std::string linha;
 int contador = 0;

 // Ler e imprimir as primeiras N linhas do arquivo
 while (std::getline(arquivo, linha) && contador < n) {
     std::cout << linha << std::endl;
     contador++;
 }

 // Fechar o arquivo
 arquivo.close();

 return 0;
}