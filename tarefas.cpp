#include <iostream>
#include <fstream> //for data manipulation in file
#include <string> //to get an entire line from cin
#include <filesystem> //for std::filesystem::exists
using std::string, std::cin, std::cout;

int main()
{
    std::ofstream file{"tarefas.txt"};
    int resposta{};
    std::string tarefa;

    while (true)
    {
        std::fstream file("tarefas.txt", std::ios::in | std::ios::out | std::ios::app);

        std::cout << "O que deseja fazer?" << '\n'
                  << "Adicionar tarefa(1) | Remover tarefa (2) | Ver tarefas(3) |Sair(4)" << '\n';
        std::cin >> resposta;
        if (resposta == 1)
        {
            std::cout << "Digite a tarefa a ser adicionada" << '\n';
            std::cin.ignore();
            std::getline(std::cin, tarefa);
            file << tarefa << '\n';
        }
        else if (resposta == 2)
        {
            std::cout << "que tarefa deseja remover(Digite a tarefa exatamente como aparece abaixo)" << '\n';
            for (std::string tarefas; std::getline(file, tarefas);)
            {
                std::cout << tarefas << '\n';
            }
        }
        else if (resposta == 3)
        {
            for (std::string conteudo; std::getline(file, conteudo);)
            {
                std::cout << '\n' << conteudo << '\n';
            }
        }
        else if (resposta == 4)
        {
            break;
        }
    }
    
}