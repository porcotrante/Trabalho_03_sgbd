#include <string>
using namespace std;

class dado
{
public:
    int writeTimestamp;
    int readTimestamp;
    int idDado;
    char nome;
    void limpar();
    int escrever(int timestamp, int escalonamento, int momento);
    int ler(int timestamp, int escalonamento, int momento);
    dado(char nome, int id);
    ~dado();
};