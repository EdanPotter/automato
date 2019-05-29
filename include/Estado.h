#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
/*
class Estado
{
    public:
        Estado();
    private:
        vector<char> transicoes;
};*/

class Automato
{
    public:
        Automato(fstream &arq);
        void gettt();
        bool testa(string palavra);

    private:
        vector<vector<vector<char>>> matrizTransicoes;
        int estado;
        vector<int> estadoFinal;
        int estadoInicial;
        int nEstados;

};
#endif // ESTADO_H
