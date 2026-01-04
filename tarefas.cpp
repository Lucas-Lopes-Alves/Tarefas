#include <iostream>
#include <fstream> //for data manipulation in file
#include <string> //to get an entire line from cin
#include <filesystem> //for std::filesystem::exists
using std::string, std::cin, std::cout;

int main() {   
    int resposta {}; //variavel criada para salvar a resposta e definir o que fazer
    std::string tarefa; //serve para pegar a tarefa a ser adicionada para colocar no arquivo
    

    while (true) //cria o loop que permite usar constantemente
    {
        //verifica se o arquivo das tarefas existe
        std::fstream file;
        if (std::filesystem::exists("tarefas.txt")) {
            file.open("tarefas.txt", std::ios::app);
        } else {
            file.open("tarefas.txt", std::ios::out | std::ios::app);
        }

        //pergunta o que o usúario deseja fazer e faz algo com base no número obtido
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
            std::cout << "Que tarefa deseja remover(Digite a tarefa exatamente como aparece abaixo)" 
                        << '\n' << "---------------------------" << '\n';
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
        else {
            cout << "Opção inválida" ;
        }
    }
    
}