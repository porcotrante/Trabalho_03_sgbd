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