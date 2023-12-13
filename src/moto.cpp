#include "veiculo.h"
#include "moto.h"
#include <string>
#include <iostream>

//CONSTRUTOR
//Recebeos dados da nova moto
Moto::Moto(string modelo, string chassi, string marca, int preco, int ano_de_fabricacao){
    setModelo(modelo);
    setChassi(chassi);
    setMarca(marca);
    setPreco(preco);
    setAno_de_fabricacao(ano_de_fabricacao);
}

//Atribui o modelo da moto
void Moto::setModelo(string mod){
    modelo = mod;
}

//Retorna o modelo da moto
string Moto::getModelo(){
    return modelo;
}

//Imprime dos dados da moto
void Moto::print_Moto(){
    cout << endl;
    cout << "MODELO: " << getModelo() << endl;
    cout << "MARCA: " << get_marca() << endl;
    cout << "PRECO: " << get_preco() << endl;
    cout << "CHASSI: " << get_chassi() << endl;
    cout << "ANO DE FABRICACAO: " << get_ano_de_fabricacao() << endl;
}