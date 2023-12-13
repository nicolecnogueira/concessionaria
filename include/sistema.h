#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include "concessionaria.h"
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class Sistema {
  private:
    vector<string> dados;
    vector<Concessionaria> concessionarias;

  public:
    //Encerra o programa
    string quit();

    //Adiciona ao vetor concessionária
    void setConcessionaria(Concessionaria concessionaria);

    //Retorna o vetor concessionária
    vector<Concessionaria> &getConcessionaria();

    //Cria uma concessionária
    string create_concessionaria (const string nome);

    //Adicionam novos veículos
    string add_car (const string nome);	
    string add_truck (const string nome);	
    string add_moto (const string nome);

    //Pesquisa o veículo no vetor
    string search_vehicle(const string chassi);

    //Remove o veículo do vetor
    string remove_vehicle(const string chassi);

    //Imprime a frota da concessionária
    string list_concessionaria(const string nome);

    //Aumenta os preços dos veículos
    string raise_price(const string nome);

    //Cria o arquivo txt
    string save_concessionaria(const string nome);
    
    //Recupera os dados do arquivo txt
    string load_concessionaria(const string nome);

    //Pesquisa a concessionária no vetor
    int search_concessionaria(const string nome);

    //Quebra a string em vetor
    vector<string> quebra_string(string str, const char* op);

    //Imprime as concessionárias
    void print_concessionaria();
};

#endif