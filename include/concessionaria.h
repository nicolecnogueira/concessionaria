#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <iostream>
#include <string>
#include <algorithm>
#include "veiculo.h"
#include "carro.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;

class Concessionaria{
    protected:
        int estoque;
        string nome;
        string CNPJ;
        double valor_carros;
        double valor_caminhoes;
        double valor_motos;

        vector<Carro> Vcarro;
        vector<Caminhao> Vcaminhao;
        vector<Moto> Vmoto;

    public:
        //CONSTRUTOR
        Concessionaria(string nom, string cnpj, int est);

        //Atribui o nome da concessionária
        void setNome(string nom);

        //Retorna o nome da concessionária
        string getNome();

        //Atribui o CNPJ da concessionária
        void setCnpj(string cnpj);

        //Retorna o CNPJ da concessionária
        string getCnpj();

        //Atribui o estoque da concessionária
        void setEstoque(int est);

        //Retorna o estoque da concessionária
        int getEstoque();

        //Adiciona ao vetor carro
        void setCarro(Carro carro);

        //Retorna o vetor carro
        vector<Carro> &getCarro();  

        //Adiciona ao vetor caminhão
        void setCaminhao(Caminhao caminhao);

        //Retorna o vetor caminhão
        vector<Caminhao> &getCaminhao(); 

        //Adiciona ao vetor moto
        void setMoto(Moto moto);

        //Retorna o vetor moto
        vector<Moto> &getMoto();   
        
        //Retorna o índice de cada veículo
        int indexCar(string chassi);
        int indexTruck(string chassi);
        int indexMoto(string chassi);

        //Pesquisa veículo no vetor
        bool search_vehicle(string chassi);

        //Remove do veículo do vetor
        bool remove_vehicle(string chassi);
};

#endif