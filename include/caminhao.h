#ifndef CAMINHAO_H
#define CAMINHAO_H
#include "veiculo.h"
#include <string>
using std::string;
#include <iostream>

#include "veiculo.h"

using namespace std;

class Caminhao : public Veiculo{
    protected:
        string carga;

    public:
        //CONSTRUTOR
        Caminhao(string carga, string chassi, string marca, int preco, int ano_de_fabricacao);
        
        //Atribui o tipo de carga do caminhão
        void setCarga(string car);

        //Retorna o tipo de carga do caminhão
        string getCarga();

        //Imprime os dados do caminhão
        void print_caminhao();
};

#endif

