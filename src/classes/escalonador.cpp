#include "../headers/escalonador.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

escalonador::escalonador(){
    ifstream arquivo("in.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        nEscalonamentos = 0;
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

    // Total de linhas lidas menos as 3 primeiras
    nEscalonamentos = linhaAtual - 3;

    arquivo.close();


    ofstream saida("out.txt");
    saida.close();
}

escalonador::~escalonador(){}