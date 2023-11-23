#include "veiculo.h"
#include <iostream>
#include <string>
using std::string;

//CONSTRUTOR
//recebe os dados do veículo
Veiculo::Veiculo()
{
    setMarca("");
    setPreco(0);
    setChassi("");
    setAno_Fabricacao(0);
}

//Retorna a marca do veiculo
string Veiculo::get_marca(){
    return marca;
}

//Retorna o preço do veiculo
int Veiculo::get_preco(){
    return preco;
}

//Retorna o chassi do veiculo
string Veiculo::get_chassi(){
    return chassi;
}

//retorna o ano de fabricação do veiculo
int Veiculo::get_ano_de_fabricacao(){
    return ano_de_fabricacao;
}

//altera a marca do veiculo
void Veiculo::set_marca(string mar){
    marca = mar;
}

//altera o preço do veiculo
void Veiculo::set_preco(double pre){
    preco = pre;
}

//altera o chassi do veiculo
void Veiculo::set_chassi(string cha){
    chassi = cha;
}

//altera o ano de fabricação do veículo
void Veiculo::set_ano_de_fabricacao(int ano){
    ano_de_fabricacao = ano;
}