#include "veiculo.h"
#include "moto.h"
#include <string>
#include <iostream>

//CONSTRUTOR
//recebe os dados da nova moto
Automoveis::Automoveis(string marca, int preco, string chassi, int ano_de_fabricacao, string modelo){
    set_marca(marca);
    set_preco(preco);
    set_chassi(chassi);
    set_ano_de_fabricacao(ano_de_fabricacao);
    set_modelo(modelo);
}

//retorna o tipo de modelo
string Carro::get_modelo(){
    return modelo;
}

//altera o tipo de modelo
void Moto::set_modelo(string mod){
    modelo = mod;
}