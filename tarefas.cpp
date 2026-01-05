#include <iostream>
#include <fstream>    //for data manipulation in file
#include <string>     //to get an entire line from cin
#include <filesystem> //for std::filesystem::exists
#include <vector>
#include <algorithm>
using std::string, std::cin, std::cout;

int main()
{
    int resposta{}; // variavel criada para salvar a resposta e definir o que fazer
    string tarefa;  // serve para pegar a tarefa a ser adicionada para colocar no arquivo
    std::vector<string> linhas;

    while (true) // cria o loop que permite usar constantemente
    {
        // verifica se o arquivo das tarefas existe
        std::fstream file;
        if (std::filesystem::exists("/home/lucas/desktop/C/tarefas.txt"))
        {
            file.open("/home/lucas/desktop/C/tarefas.txt", std::ios::in | std::ios::app);
        }
        else
        {
            file.open("/home/lucas/desktop/C/tarefas.txt", std::ios::in | std::ios::out | std::ios::app);
        }

        // pergunta o que o usúario deseja fazer e faz algo com base no número obtido
        cout << "O que deseja fazer?" << '\n'
             << "Adicionar tarefa(1) | Remover/Substituir tarefa (2) | Ver tarefas(3) | Sair(4)" << '\n';
        cin >> resposta;
        cout << '\n';
        if (resposta == 1)
        {
            // limpa o cin e pega a tarefa a ser adicionada no arquivo
            cout << "Digite a tarefa a ser adicionada" << '\n';
            cin.ignore();
            std::getline(std::cin, tarefa);
            file << tarefa << '\n';
        }
        else if (resposta == 2)
        {
            int pergunta{};
            cout << "Deseja remover(1) ou substituir(2) uma tarefa" << '\n';
            cin >> pergunta;
            if (pergunta == 1)
            {
                // lê o conteudo do arquivo imprime e salva no vetor para mudar o conteudo
                // e depois adiciona de volta no arquivo
                cout << "Que tarefa deseja remover(Digite o número da tarefa)"
                     << '\n'
                     << "---------------------------" << '\n';
                string tarefas;
                int removido;
                int count{0};
                while (std::getline(file, tarefas))
                {
                    cout << count + 1 << ": " << tarefas << '\n';
                    linhas.push_back(tarefas);
                    count++;
                }
                cin.ignore();
                cin >> removido;

                file.close();
                linhas.erase(linhas.begin()+(removido-1));

                std::fstream file("/home/lucas/desktop/C/tarefas.txt", std::ios::out);

                for (std::string vetor : linhas)
                {
                    file << vetor << '\n';
                }
            }
            else if (pergunta == 2)
            {
                cout << "Qual tarefa deseja substituir? (Escreva o número da tarefa)" << '\n';
                string conteudo;
                int count{};
                while (std::getline(file, conteudo))
                {
                    cout << count + 1 << ": " << conteudo << '\n';
                    linhas.push_back(conteudo);
                    count++;
                }
                int resposta{};
                string substituto{};
                cin >> resposta;
                cout << "Escreva a nova tarefa" << '\n';
                cin.ignore();
                std::getline(cin, substituto);
                linhas[resposta - 1] = substituto;

                file.close();
                std::fstream file("/home/lucas/desktop/C/tarefas.txt", std::ios::out);

                for (std::string vetor : linhas)
                {
                    file << vetor << '\n';
                }
            }
            else
            {
                cout << "Operação inválida" << '\n';
            }
        }
        else if (resposta == 3)
        {
            // imprime cada linha do arquivo com o numero da linha do lado
            int count{};
            string conteudo;
            cout << "-------------------------------------------------------------------------------" << '\n';
            while (std::getline(file, conteudo))
            {
                cout << count + 1 << ": " << conteudo << '\n';
                count++;
            }
            cout << "-------------------------------------------------------------------------------" << '\n';
        }
        else if (resposta == 4)
        {
            // para o programa
            break;
        }
        else
        {
            // resposta caso seja colocada uma opção inválida
            cout << '\n'
                 << "Opção inválida" << '\n'
                 << '\n';
            break;
        }
    }
}