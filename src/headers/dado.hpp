#include <string>
using namespace std;

class dado
{
public:
    int writeTimestamp;
    int readTimestamp;
    int idDado;
    string nome;
    void limpar();
    int escrever(int timestamp, int escalonamento, int momento);
    int ler(int timestamp, int escalonamento, int momento);
    dado(string nome, int id);
    ~dado();
};