#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
int opcaoInicial;

int main()
{

    // Entrada - declaração das variáveis
    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;

    // Processamento

    // Leitura de alunos (Commit 1)
    cout << "=== SISTEMA DE NOTAS v4.1 ===" << endl;
    cout << "1- Novo relatorio" << endl;
    cout << "2- Ver relatorio salvo" << endl;
    cout << "3- Sobre o sistema" << endl;
    cout << "Escolha a opcao" << endl;
    cin >> opcaoInicial;

    // Leitura de arquivo (Commit 5)
    if (opcaoInicial == 2)
    {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\n";
            while (getline(leitura, linha))
            {
                cout << linha << endl;
            }
            leitura.close();
        }
        else
        {
            cout << "Nenhum relatorio encontrado." << endl;
        }
        return 0;
    }


    else if (opcaoInicial == 3){
    cout << "=== Sobre o sistema ===" << endl;
    cout << "Desenvolvido por: Laura Nunes Semensato" << endl;
    cout << "Turma LOPAL 2026 - SENAI-SP" << endl;
    }

    do
    {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Nome do aluno: " << i + 1 << ":";
        getline(cin, nomes[i]);
    }

    // Notas e medias (Commit 2)
    do
    {
        cout << "\nQuantidade de disciplinas (1 a 5): ";
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplinas; j++)
        {
            do
            {
                cout << "Disciplina " << j + 1 << "(1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    // Saida
    cout << "\nAlunos cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << " " << i + 1 << ". " << nomes[i] << endl;
    }

    // Classificacao e relatorios (Commit 3)
    cout << "\n=== RELATÓRIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << nomes[i] << "-Media: " << media[i] << " - ";
        if (media[i] >= 7)
        {
            cout << "Aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "Recuperação" << endl;
            recuperacao++;
        }
        else
        {
            cout << "Reprovados" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << " aprovados: " << recuperacao << " em recuperacao: " << reprovados << " reprovados: " << endl;

    // Salvar em arquivos (Commit 4)
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {
    
        arquivo << "=== RELATORIO ===" << endl;
        for (int i = 0; i < qtdAlunos; i++)
        {
            arquivo << nomes[i] << "- Média : " << media[i] << "-";
            if (media[i] >= 7)
            {
                arquivo << "aprovado" << endl;
            }
            else if (media[i] >= 5)
            {
                arquivo << "Recuperacao" << endl;
            }
            else
            {
                arquivo << "Reprovado" << endl;
            }
            time_t agora = time(0);
char* dataHora = ctime(&agora);
arquivo << "Data do relatorio: " << dataHora << endl;
        }
        arquivo << "\nResumo: " << aprovados << " aprovados" << recuperacao << " recuperacao" << reprovados << " reprovados" << endl;
        arquivo.close();
        cout << "\nRelatorio salvo em relatrio.txt" << endl;
    }
    else
    {
        cout << "Erro ao criar arquivo." << endl;
    }
    return 0;
}