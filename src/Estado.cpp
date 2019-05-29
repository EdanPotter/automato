#include "Estado.h"
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

Automato::Automato(fstream &arq)
{
    int v;
    arq >> v;
    nEstados = v;
    arq >> v;
    estadoInicial = v;
    int numeroFinais;
    arq >> numeroFinais;

    for(int i=0; i<numeroFinais; i++)
    {
        int num;
        arq >> num;
        estadoFinal.push_back(num);
    }


    for(int i=0; i<nEstados; i++) //Constroi matriz vazia
    {
        vector<vector<char>> aux;
        for(int j=0; j<nEstados; j++)
        {
            vector<char> aux2;
            aux.push_back(aux2);
        }
        matrizTransicoes.push_back(aux);
    }

    int atual;
    int prox;
    char trans;

    while(!arq.eof()) //Coloca elementos na matriz
    {
        arq >> atual;
        arq >> trans;
        arq >> prox;
        matrizTransicoes.at(atual).at(prox).push_back(trans);
    }
}
void Automato::gettt()
{
    cout << nEstados << endl;
    cout << estadoInicial << endl;
    for(int i=0; i<estadoFinal.size(); i++)
        cout << estadoFinal.at(i) << endl;
    for(int i=0; i<matrizTransicoes.size(); i++) //Escreve elementos na matriz
    {
        for(int j=0; j<matrizTransicoes.at(i).size(); j++)
        {
            for(int k=0; k<matrizTransicoes.at(i).at(j).size(); k++)
                cout << i << " " << matrizTransicoes.at(i).at(j).at(k) << " " << j << endl;
        }
    }
}
bool Automato::testa(string palavra)
{
    int atual = estadoInicial;
    int prox;
    int flag = 0;
    for(int i=0; i<palavra.size(); i++)
    {
        char c = palavra.at(i);
        for(int j=0; j<matrizTransicoes.at(atual).size(); j++)
        {
            for(int k=0; k<matrizTransicoes.at(atual).at(j).size(); k++)
            {
                if(c == matrizTransicoes.at(atual).at(j).at(k))
                {
                    prox = j;
                    flag = 1;
                }
            }
        }
        if(flag)
        {
            atual = prox;
            flag = 0;
        }
        else
            return false;
    }
    for(int i=0; i<estadoFinal.size(); i++)
        if(atual == estadoFinal.at(i))
            return true;

    return false;
}
