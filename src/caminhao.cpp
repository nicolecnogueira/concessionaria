#include "veiculo.h"
#include "caminhao.h"
#include <string>
#include <iostream>

//CONSTRUTOR
//recebe os dados do novo caminhao
Automoveis::Automoveis(string marca, int preco, string chassi, int ano_de_fabricacao, string carga){
    set_marca(marca);
    set_preco(preco);
    set_chassi(chassi);
    set_ano_de_fabricacao(ano_de_fabricacao);
    set_carga(carga);
}

//retorna o tipo de carga
string Carro::get_carga(){
    return carga;
}

//altera o tipo de carga
void Caminhao::set_carga(string car){
    carga = car;
}