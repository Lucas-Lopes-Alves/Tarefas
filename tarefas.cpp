#include <iostream>
#include <fstream> //for data manipulation in file
#include <string> //to get an entire line from cin
#include <filesystem> //for std::filesystem::exists
#include <vector>
using std::string, std::cin, std::cout;

int main() {   
    int resposta {}; //variavel criada para salvar a resposta e definir o que fazer
    string tarefa; //serve para pegar a tarefa a ser adicionada para colocar no arquivo
    std::vector<string> linhas;
    

    while (true) //cria o loop que permite usar constantemente
    {
        //verifica se o arquivo das tarefas existe
        std::fstream file;
        if (std::filesystem::exists("/home/lucas/desktop/C/tarefas.txt")) {
            file.open("/home/lucas/desktop/C/tarefas.txt", std::ios::in | std::ios::app);
        } else {
            file.open("/home/lucas/desktop/C/tarefas.txt", std::ios::in | std::ios::out | std::ios::app);
        }

        //pergunta o que o usúario deseja fazer e faz algo com base no número obtido
        cout << "O que deseja fazer?" << '\n'
                  << "Adicionar tarefa(1) | Remover/Substituir tarefa (2) {Em construção} | Ver tarefas(3) | Sair(4)" << '\n';
        cin >> resposta;
        cout << '\n';
        if (resposta == 1)
        {
            //limpa o cin e pega a tarefa a ser adicionada no arquivo
            cout << "Digite a tarefa a ser adicionada" << '\n';
            cin.ignore();
            std::getline(std::cin, tarefa);
            file << tarefa << '\n';
        }
        else if (resposta == 2)
        {
            cout << "Que tarefa deseja remover(Digite a tarefa exatamente como aparece abaixo)" 
                        << '\n' << "---------------------------" << '\n';
            string tarefas;
            string removido;
            int count{0};
            while (std::getline(file, tarefas))
            {
                cout << count <<": "<< tarefas << '\n';
                linhas.push_back(tarefas);
                count++;
            }
            cin.ignore();
            std::getline(cin, removido);
            count = 0;
            while (std::getline(file, tarefas))
            {
                if (tarefas == removido) {
                    linhas.erase(linhas.begin() + count);
                }
                count++;
            }
            
        }
        else if (resposta == 3)
        {
            //imprime cada linha do arquivo
            string conteudo;
            cout << "-------------------------------------------------------------------------------" << '\n' ;
            while (std::getline(file, conteudo))
            {
                cout << conteudo << '\n';
            }
            cout << "-------------------------------------------------------------------------------" << '\n' ;
        }
        else if (resposta == 4)
        {
            //para o programa
            break;
        }
        else {
            //resposta caso seja colocada uma opção inválida
            cout << '\n' << "Opção inválida" << '\n' <<'\n' ;
            break;
        }
    }
    
}