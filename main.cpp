#include <iostream>
#include "./src/headers/dado.hpp"
using namespace std;

int main() {
    dado X = dado("X",1);

    cout << X.idDado << " " << X.nome << endl;
}