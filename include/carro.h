#ifndef CARRO_H
#define CARRO_H
#include <iostream>

#include "veiculo.h"

using namespace std;

class Carro : public Veiculo{
    protected:
        string motor;

    public:
        //CONSTRUTOR
        Carro(string motor, string chassi, string marca, int preco, int ano_de_fabricacao);

        //Atribui o tipo de motor do carro
        void setMotor(string mot);

        //Retorna o tipo de motor do carro
        string getMotor();

        //Imprime os dados do carro
        void print_carro();
};

#endif