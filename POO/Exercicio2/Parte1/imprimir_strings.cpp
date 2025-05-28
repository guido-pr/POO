#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
 std::string nomeArquivo;
 std::vector<std::string> strings;
 std::string entrada;

 // Solicitar ao usuário o nome do arquivo onde as strings serão salvas
 std::cout << "Digite o nome do arquivo para salvar as strings: ";
 std::cin >> nomeArquivo;

 std::cout << "Digite as strings (digite 'fim' para finalizar):" << std::endl;

 // Ler strings do usuário até que ele digite "fim"
 while (true) {
     std::cin.ignore();  // Ignorar qualquer caractere residual no buffer
     std::getline(std::cin, entrada);  // Ler uma linha completa

     if (entrada == "fim") {
         break;  // Parar quando o usuário digitar "fim"
     }

     strings.push_back(entrada);  // Armazenar a string na lista
 }

 // Abrir o arquivo para escrita
 std::ofstream arquivo(nomeArquivo);

 if (!arquivo.is_open()) {
     std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
     return 1;  // Encerrar o programa com código de erro
 }

 // Escrever as strings no arquivo
 for (const auto& str : strings) {
     arquivo << str << std::endl;
 }

 // Fechar o arquivo
 arquivo.close();

 std::cout << "Strings salvas no arquivo: " << nomeArquivo << std::endl;

 return 0;
}