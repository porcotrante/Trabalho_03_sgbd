#include <iostream>
#include <vector>
#include "./src/headers/dado.hpp"
#include "./src/headers/escalonador.hpp"
using namespace std;

int main() {
    // Criar os dados baseados no arquivo in.txt (primeira linha: A, B, C, D)
    vector<dado> dados;
    dados.push_back(dado('X', 1));
    dados.push_back(dado('Y', 2));
    dados.push_back(dado('W', 3));
    dados.push_back(dado('Z', 4));

    // Criar o escalonador (ele já lê automaticamente o arquivo in.txt no construtor)
    escalonador esc;

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