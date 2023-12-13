#ifndef MOTO_H
#define MOTO_H
#include <iostream>

#include "veiculo.h"

using namespace std;

class Moto : public Veiculo{
    protected:
        string modelo;

    public:
        //CONSTRUTOR
        Moto(string modelo, string chassi, string marca, int preco, int ano_de_fabricacao);

        //Atribui o modelo da moto
        void setModelo(string mod);

        //Retorna o modelo da moto
        string getModelo();

        //Imprime os dados da moto
        void print_Moto();
};

#endif