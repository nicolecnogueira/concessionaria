#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */

//função que encerra o programa
string Sistema::quit() {
  return "Saindo...";
}
//função que cria a concessionária
string Sistema::create_concessionaria (const string nome) {
  dados = quebra_string(nome, " ");

    int i = search_concessionaria(dados[0]);
    if (i == -1)
    {
      Concessionaria n_con(dados[0], dados[1], stoi(dados[2]));
      set_concessionaria(n_con);
    }

    else
    {
      return "Concessionaria ja adicionada";
    }
    
    return "create_concessionaria";
}

//recebe uma string com os dados da concessionária e retorna um vetor com os dados separados
vector<string> Sistema::quebra_string(string str, const char* op) {
    vector<string> p;

    string resto = str, bloco;
    size_t operator_position = resto.find_first_of(op);

    while (operator_position != string::npos){
        bloco = resto.substr(0, operator_position);
        resto = resto.substr(operator_position + 1);
        operator_position = resto.find_first_of(op);
        p.push_back(bloco);
    }

    if (resto.length() > 0){
        p.push_back(resto);
    }

    return p;  
}

//busca concessionária
int Sistema::search_concessionaria(const string nome){
    for (int i = 0; i < (int)get_concessionaria().size(); i++){
      if (get_concessionaria()[i].get_nome() == nome){
        return i;
      }
    }
    return -1;
}

//adiciona uma nova concessionária ao vetor
void Sistema::set_concessionaria(Concessionaria concessionaria){
    concessionaria.push_back(concessionaria);
}

//adiciona um novo carro
string Sistema::add_car(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria nao encontrada\n";
    }
    
    if(get_concessionaria().at(i).search_vehicle(dados[3])){
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionaria[i].get_nome() == dados[0]){      
      Carro car(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionaria[i].set_carro(car);
      concessionaria[i].set_estoque(concessionaria[i].get_estoque() + 1);
      return "add-car";
    }
    
    return "ERRO add-car";
}

//adiciona uma nova moto
string Sistema::add_bike(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria nao encontrada\n";
    }

    if(getConcessionaria().at(i).search_vehicle(dados[3])){
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].get_nome() == dados[0]){
      Moto moto(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].set_moto(moto);
      concessionarias[i].set_estoque(concessionarias[i].get_estoque() + 1);
      return "add-bike";
    }

    return "ERRO add-bike";
}

string Sistema::add_truck(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria não encontrada\n";
    }

    if(get_concessionaria().at(i).search_vehicle(dados[3])){
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionaria[i].get_nome() == dados[0]){
      Caminhao truck(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionaria[i].set_caminhao(truck);
      concessionaria[i].set_estoque(concessionaria[i].get_estoque() + 1);
      return "add-truck";
    }
      
    return "ERRO add-truck";
      
}

//busca veículo
string Sistema::search_vehicle(const string chassi){
    for (int i = 0; i < (int) get_concessionaria().size(); i++){
      if(get_concessionaria().at(i).search_vehicle(chassi)){
        cout << "CONCESSIONARIA: " << get_concessionaria().at(i).get_nome() << endl;
        return " ";
      }
    }
    return "Veiculo não encontrado\n";
}

//remove veículo
string Sistema::remove_vehicle(const string chassi){
    for (int i = 0; i < (int) get_concessionaria().size(); i++){
      if(get_concessionaria().at(i).search_vehicle(chassi)){
        get_concessionaria()[i].remove_vehicle(chassi);
        get_concessionaria()[i].set_estoque(get_concessionaria()[i].get_estoque() - 1);
        return "remove-vehicle\n";
      }
    }
    return "Veiculo não encontrado\n";
}


/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
