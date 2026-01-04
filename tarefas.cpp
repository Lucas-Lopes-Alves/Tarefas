#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream file{"tarefas.txt"};
    int resposta{};
    std::string tarefa;

    while (true)
    {
        std::fstream file("tarefas.txt", std::ios::in | std::ios::out | std::ios::app);

        std::cout << "O que deseja fazer?" << '\n'
                  << "Adicionar tarefa(1) | Remover tarefa (2) | Sair(3)";
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
            
        }
        else if (resposta == 3)
        {
            break;
        }
    }
}