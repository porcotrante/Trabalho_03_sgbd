#include "../headers/dado.hpp"
#include <fstream>
#include <string>

using namespace std;

dado::dado(char nome, int id) {
    this->idDado = id;
    this->readTimestamp = 0;
    this->writeTimestamp = 0;
    this->nome = nome;
    // Criar o arquivo "nome.txt"
    ofstream arquivo(string(1, nome) + ".txt");
    if (arquivo.is_open()) {
        arquivo.close();
    }
}

void dado::limpar(){
    this->readTimestamp = 0;
    this->writeTimestamp = 0;
}

int dado::escrever(int timestamp, int escalonamento, int momento){
    if (timestamp < readTimestamp || timestamp < writeTimestamp)
    {
        return 0; //transação inválida, fazer rollback
    }

    this->writeTimestamp = timestamp;

    ofstream arquivo(string(1, nome) + ".txt");
    if (arquivo.is_open()) {
        arquivo << "E_" << escalonamento << "; " << "WRITE; " << momento << ";" << endl;
        arquivo.close();
    }

    return 1;
}

int dado::ler(int timestamp, int escalonamento, int momento){
        if (timestamp < writeTimestamp)
    {
        return 0; //transação inválida, fazer rollback
    }

    this->readTimestamp = timestamp;

    ofstream arquivo(string(1, nome) + ".txt");
    if (arquivo.is_open()) {
        arquivo << "E_" << escalonamento << "; " << "READ; " << momento << ";" << endl;
        arquivo.close();
    }
    return 1;
}

dado::~dado() {}