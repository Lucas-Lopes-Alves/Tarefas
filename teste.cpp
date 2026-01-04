#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main() {
    std::vector<std::string> lista;
    std::fstream file("tarefas.txt", std::ios::in | std::ios::out | std::ios::app);
    std::string conteudo;
    while (std::getline(file, conteudo)) {
        lista.push_back(conteudo);
    }

    for (std::string coisos : lista) {
        std::cout << coisos << '\n';
    }

    std::string resposta;
    std::getline(std::cin, resposta);
    

}