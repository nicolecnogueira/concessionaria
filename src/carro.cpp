#include "veiculo.h"
#include "carro.h"
#include <string>
#include <iostream>

//CONSTRUTOR
//Recebe os dados do novo carro
Carro::Carro(string motor, string chassi, string marca, int preco, int ano_de_fabricacao){
    setMotor(motor);
    setMarca(marca);
    setPreco(preco);
    setChassi(chassi);
    setAno_de_fabricacao(ano_de_fabricacao);
}

//Atribui o tipo de motor do carro
void Carro::setMotor(string mot){
    motor = mot;
}

//Retorna o tipo de motor do carro
string Carro::getMotor(){
    return motor;
}

//Imprime os dados do carro
void Carro::print_carro() {
    cout << endl;
    cout << "TIPO DE MOTOR: " << getMotor() << endl;
    cout << "MARCA: " << get_marca() << endl;
    cout << "PRECO: " << get_preco() << endl;
    cout << "CHASSI: " << get_chassi() << endl;
    cout << "ANO DE FABRICACAO: " << get_ano_de_fabricacao() << endl;
}