#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "./src/headers/dado.hpp"
#include "./src/headers/escalonador.hpp"
using namespace std;

int main() {
    // Criar os dados baseados no arquivo in.txt (primeira linha: A, B, C, D;)
    vector<dado> dados;
    ifstream entrada("in.txt");
    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo in.txt." << endl;
        return 1;
    }
    else {
        string primeiraLinha;
        getline(entrada, primeiraLinha);
        
        char caractere;
        int contador = 1;
        int i = 0;
        
        // Usar while com ; como ponto de parada
        while (i < primeiraLinha.size()) {
            caractere = primeiraLinha[i];
            
            // Para quando encontrar o ponto e vírgula
            if (caractere == ';') {
                break;
            }
            
            // Se o caractere é uma letra maiúscula (A-Z)
            if (caractere >= 'A' && caractere <= 'Z') {
                dados.push_back(dado(caractere, contador));
                cout << "Criado dado: " << caractere << " (ID: " << contador << ")" << endl;
                contador++;
            }
            
            i++;
        }
    }
    entrada.close();

    // Criar o escalonador (ele já lê automaticamente o arquivo in.txt no construtor)
    escalonador esc = escalonador();

    cout << "Timestamps carregados: ";
    for (int timestamp : esc.timestamps) {
        cout << timestamp << " ";
    }
    cout << endl;

    // Validar os escalonamentos
    cout << "Iniciando validacao dos escalonamentos..." << endl;
    esc.validar(dados);
    cout << "Validacao concluida. Verifique o arquivo out.txt para os resultados." << endl;

    return 0;
}