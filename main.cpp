#include <iostream>
#include <fstream>
#include "Estado.h"
using namespace std;

int main()
{
    fstream alf;
    alf.open("DEFINICAO.txt", fstream::in);

    Automato a(alf);
    a.gettt();
    cout << a.testa("ab");

    return 0;
}
