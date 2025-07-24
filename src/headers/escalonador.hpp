#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP
#include <vector>
#include "dado.hpp"
using namespace std;

class escalonador
{
public:
    vector<int> timestamps;
    void validar(vector<dado> dados);
    escalonador();
    ~escalonador();
};
#endif
