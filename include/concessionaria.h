#infdef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <iostream>
#include "carro.h"
#include "moto.h"
#include "caminhao.h"
#include <string>

using namespace std;

class Concessionaria{
    protected:
    string nome;
    string CNPJ;
    int estoque;
    int quant_carro = 0;
    int quant_moto = 0;
    int quant_caminhao = 0;

    vector<Carro> Vcarro;
    vector<Moto> Vmoto;
    vector<Caminhao> Vcaminhao;

    public:

    //construtor
    Concessionaria(string nom, string cnpj, int est);
    
    void set_nome();		//recebe o nome da concessionária
	void set_CNPJ();		//recebe o CNPJ da concessionária
	void set_estoque();		//recebe o estoque da concessionária

    string get_nome();		//retorna o nome da concessionária
	string get_cnpj();		//retorna o CNPJ da concessionária
	int get_estoque();		//retorna o estoque da concessionária

    //vetor de carros
    vector<Carro> &get_carro();
    void set_carro(Carro carro);

    //vetor de motos
    vector<Moto> &get_moto();
    void set_moto(Moto moto);

    //vetor de caminhões
    vector<Caminhao> &get_caminhao();
    void set_caminhao(Caminhao caminhao);

    int get_quant_caro(); 	    //retorna a quantidade de carros
	int get_quant_moto();   	//retorna a quantidade de motos
	int get_quant_caminhao();	//retorna a quantidade de caminhões
		
	void add_quant_carro();	    //adiciona 1 na quantidade de carros
	void add_quant_moto();	    //adiciona 1 na quantidade de motos
	void add_quant_caminhao();	//adiciona 1 na quantidade de caminhões
		
	void sub_quant_carro();	    //subtrai 1 na quantidade de carros
	void sub_quant_moto();	    //subtrai 1 na quantidade de motos
	void sub_quant_caminhao();	//subtrai 1 na quantidade de caminhões
		
	void soma_estoque(); 	    //soma de todos os veículos do estoque

    //retorna o indice do veiculo em reu respectivo vetor
    int index_carro(string chassi);
    int index_moto(string chassi);
    int index_caminhao(string chassi);

    //pesquisa o veiculo no vetor (para saber se ele já está na concessionária)
    bool buscar_veiculo(string chassi);

    //remove o veiculo
    void remover_veiculo(string chassi);
		

}

#endif