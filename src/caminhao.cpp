#include "veiculo.h"
#include "caminhao.h"
#include <string>
#include <iostream>

//CONSTRUTOR
//Recebe os dados do novo caminhão
Caminhao::Caminhao(string carga, string chassi, string marca, int preco, int ano_de_fabricacao){
    setCarga(carga);
    setChassi(chassi);
    setMarca(marca);
    setPreco(preco);
    setAno_de_fabricacao(ano_de_fabricacao);
}

//Atribui o tipo de carga do caminhão
void Caminhao::setCarga(string car){
    carga = car;
}

//Retorna tipo de carga do caminhão
string Caminhao::getCarga(){
    return carga;
}

//Imprime os dados do caminhão
void Caminhao::print_caminhao() {
    cout << endl;
    cout << "TIPO DE CARGA: " << getCarga() << endl;
    cout << "MARCA: " << get_marca() << endl;
    cout << "PRECO: " << get_preco() << endl;
    cout << "CHASSI: " << get_chassi() << endl;
    cout << "ANO DE FABRICACAO: " << get_ano_de_fabricacao() << endl;
}