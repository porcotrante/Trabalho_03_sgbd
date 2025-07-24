#include "../headers/escalonador.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

escalonador::escalonador(){
    ifstream arquivo("in.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string linha;
    int linhaAtual = 0;

    while (getline(arquivo, linha))
    {
        linhaAtual++;

        if (linhaAtual == 3)
        {
            // Terceira linha → timestamps
            stringstream ss(linha);
            string valor;
            while (getline(ss, valor, ','))
            {
                // Remover espaços em branco
                valor.erase(remove_if(valor.begin(), valor.end(), ::isspace), valor.end());
                if (!valor.empty())
                    timestamps.push_back(stoi(valor));
            }
        }
    }

    arquivo.close();
}

void escalonador::validar(vector<dado> dados){
    ifstream entrada("in.txt");
    ofstream saida("out.txt");
    if (!saida.is_open() || !entrada.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string linha;
    int linhaAtual = 0;
    bool rollback_ocorreu = false;
    int momento = 0;
    while (getline(entrada, linha))
    {
        linhaAtual++;
        rollback_ocorreu = false;
        momento = 0;
        if (linhaAtual < 4) continue;
        for (size_t i = 0; i < linha.size(); i++) {
            char c = linha[i];

            if (c == 'r' || c == 'w') {
                if (i + 1 < linha.size() && isdigit(linha[i + 1])) {
                    int transacao = linha[i+1] - '0';
                    char dado = linha[i+3];

                    for (int j = 0; j < dados.size(); j++)
                    {
                        if (dados[j].nome == dado)
                        {
                            int resultado;
                            if (c == 'r')
                            {
                                int resultado = dados[j].ler(timestamps[transacao], linhaAtual-3, momento);
                                
                            }
                            else
                            {
                                int resultado = dados[j].escrever(timestamps[transacao], linhaAtual-3, momento);
                            }

                            if (resultado == 0)
                            {
                                saida << "E_" << linhaAtual-3 << "-ROLLBACK-" << momento << endl;
                                rollback_ocorreu = true;
                                break;
                            }
                        }
                    }
                    momento++;
                }
            }
            if (c == 'c') //em caso de commit
            {
            for (int i = 0; i < dados.size(); i++)
            {
                dados[i].limpar(); //limpar as estruturas de dados para o próximo escalonamento
            }
            }
            
            if (rollback_ocorreu) break;
        }

        if (!rollback_ocorreu)
        {  
            for (int i = 0; i < dados.size(); i++)
            {
                dados[i].limpar(); //limpar as estruturas de dados para o próximo escalonamento
            }
            
            saida << "E_" << linhaAtual-3 << "OK" << endl;
        }
    }

    entrada.close();
    saida.close();
}

escalonador::~escalonador(){}