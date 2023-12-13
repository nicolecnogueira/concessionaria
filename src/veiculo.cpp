#include "veiculo.h"
#include <iostream>
#include <string>
using std::string;

//CONSTRUTOR
Veiculo::Veiculo(){
    setChassi("");
    setMarca("");
    setPreco(0);
    setAno_de_fabricacao(0);
}

//Atribui a marca do veículo
void Veiculo::setMarca(string mar){
    marca = mar;
}

//Retorna a marca do veiculo
string Veiculo::get_marca(){
    return marca;
}

//Atribui o preço do veículo
void Veiculo::setPreco(int pre){
    preco = pre;
}

//Retorna o preço do veiculo
int Veiculo::get_preco(){
    return preco;
}

//Atribui o chassi do veículo
void Veiculo::setChassi(string cha){
    chassi = cha;
}

//Retorna o chassi do veiculo
string Veiculo::get_chassi(){
    return chassi;
}

//Atribui o ano de fabricação do veículo
void Veiculo::setAno_de_fabricacao(int ano){
    ano_de_fabricacao = ano;
}

//retorna o ano de fabricação do veiculo
int Veiculo::get_ano_de_fabricacao(){
    return ano_de_fabricacao;
}