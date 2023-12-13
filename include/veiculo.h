#ifndef VEICULOS_H
#define VEICULOS_H
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Veiculo{
    protected:
        string chassi;
        string marca;
        int preco;
        int ano_de_fabricacao;

    public:
        //CONSTRUTOR
        Veiculo();

        //Atribui o chassi do veículo
        void setChassi(string cha);

        //Retorna o chassi do veículo
        string get_chassi();

        //Atribui a marca do veículo
        void setMarca(string mar);

        //Retorna a marca do veículo
        string get_marca();

        //Atribui o preço do veículo
        void setPreco(int pre);

        //Retorna o preço do veículo
        int get_preco();

        //Atribui o ano de fabricação do veículo
        void setAno_de_fabricacao(int ano);
        
        //Retorna o ano de fabricação do veículo
        int get_ano_de_fabricacao();

};

#endif