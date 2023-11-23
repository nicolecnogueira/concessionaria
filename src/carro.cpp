#include "veiculo.h"
#include "carro.h"
#include <string>
#include <iostream>

//CONSTRUTOR
//recebe os dados do novo carro
Automoveis::Automoveis(string marca, int preco, string chassi, int ano_de_fabricacao, string motor){
    set_marca(marca);
    set_preco(preco);
    set_chassi(chassi);
    set_ano_de_fabricacao(ano_de_fabricacao);
    set_motor(motor);
}

//retorna o tipo de motor
string Carro::get_motor(){
    return motor;
}

//altera o tipo de motor
void Carro::set_motor(string mot){
    motor = mot;
}