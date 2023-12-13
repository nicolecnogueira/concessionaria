#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

//Encerra o programa
string Sistema::quit() {
    return "Saindo...";
}

//Recebe os dados da nova concessionaria e retorna "create-concessionária" se criar ou "concessionária já criada" se a concessionária já existir
string Sistema::create_concessionaria (const string nome) {
    dados = quebra_string(nome, " ");

    int i = search_concessionaria(dados[0]);
    if (i == -1){
      Concessionaria n_con(dados[0], dados[1], stoi(dados[2]));
      setConcessionaria(n_con);
    }

    else{
      return "concessionaria ja adicionada";
    }

    return "create-concessionaria";
}

//Recebe uma string e quebra em partes de um vetor
vector<string> Sistema::quebra_string(string str, const char* op){
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

//Adiciona a nova concessionária ao vetor
void Sistema::setConcessionaria(Concessionaria concessionaria){
    concessionarias.push_back(concessionaria);
}

//Retorna o vetor concessionaria
vector<Concessionaria> &Sistema::getConcessionaria(){
    return concessionarias;
}

//Imprime todas as concessionarias
void Sistema::print_concessionaria() {
    for (int i = 0; i < (int)concessionarias.size(); i++)
    {
      cout << "Concessionaria: " << concessionarias[i].getNome() << endl;
      cout << "CNPJ: " << concessionarias[i].getCnpj() << endl;
      cout << "Estoque: " << concessionarias[i].getEstoque() << endl << endl;
    } 
}

//Adiciona um novo carro ao vetor e retorna "Carro adicionado" se foi adicionado ou uma mensagem de erro se não foi
string Sistema::add_car(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria nao encontrada\n";
    }


    if(getConcessionaria().at(i).search_vehicle(dados[3])){
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].getNome() == dados[0]){      
      Carro car(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].setCarro(car);
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);
      return "Carro adicionado";
    }

    return "ERRO add-car";

}

//Adiciona um novo caminhão ao vetor e retorna "caminhão adicionado" se foi adicionado ou uma mensagem de erro se não foi
string Sistema::add_truck(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria nao encontrada\n";
    }

    if(getConcessionaria().at(i).search_vehicle(dados[3])){
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].getNome() == dados[0]){
      Caminhao truck(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].setCaminhao(truck);
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);
      return "Caminhão adicionado";
    }

    return "ERRO add-truck";

}

//Adiciona uma nova moto ao vetor e retorna "Moto adicionada" se foi adicionada ou uma mensagem de erro se não foi
string Sistema::add_moto(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria nao encontrada\n";
    }

    if(getConcessionaria().at(i).search_vehicle(dados[3])){
      cout << "ERRO - Veiculo " << dados[3] << " ja adicionado a concessionaria " << dados[0] << endl;
      return " ";
    }

    if (concessionarias[i].getNome() == dados[0]){
      Moto moto(dados[5], dados[2], dados[1], stof(dados[3]), stoi(dados[4]));
      concessionarias[i].setMoto(moto);
      concessionarias[i].setEstoque(concessionarias[i].getEstoque() + 1);
      return "Moto adicionada";
    }

    return "ERRO add-bike";
}

//Recebe um chassi e retorna os dados do veículo associado a ele ou uma mensagem de erro
string Sistema::search_vehicle(const string chassi){
    for (int i = 0; i < (int) getConcessionaria().size(); i++){
      if(getConcessionaria().at(i).search_vehicle(chassi)){
        cout << "CONCESSIONARIA: " << getConcessionaria().at(i).getNome() << endl;
        return " ";
      }
    }
    return "Veiculo nao encontrado\n";
}

//Recebe o chassi e remove o veiculo associado a ele. Se remover, retorna "Veículo removido", se não, retorna uma mensagem de erro
string Sistema::remove_vehicle(const string chassi){
    for (int i = 0; i < (int) getConcessionaria().size(); i++){
      if(getConcessionaria().at(i).search_vehicle(chassi)){
        getConcessionaria()[i].remove_vehicle(chassi);
        getConcessionaria()[i].setEstoque(getConcessionaria()[i].getEstoque() - 1);
        return "Veículo removido\n";
      }
    }
    return "Veiculo nao encontrado\n";
}

//Recebe o nome da concessionária e retorna o index dela no vetor
int Sistema::search_concessionaria(const string nome){
    for (int i = 0; i < (int)getConcessionaria().size(); i++){
      if (getConcessionaria()[i].getNome() == nome){
        return i;
      }
    }
    return -1;
}

//Recebe o nome da concessionaria e retorna sua frota ou uma mensagem de erro
string Sistema::list_concessionaria(const string nome){
    int i = search_concessionaria(nome);

    if (i == -1){
      return "Concessionaria nao encontrada";
    }

    double valor_carro = 0, valor_moto = 0, valor_caminhao = 0, valor_total = 0;

    for (int j = 0; j < (int)getConcessionaria()[i].getCarro().size(); j++){
      valor_carro += getConcessionaria()[i].getCarro()[j].get_preco();
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getCaminhao().size(); j++){
      valor_caminhao += getConcessionaria()[i].getCaminhao()[j].get_preco();
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getMoto().size(); j++){
      valor_moto += getConcessionaria()[i].getMoto()[j].get_preco();
    }

    valor_total = valor_caminhao + valor_carro + valor_moto;

    cout << endl;
    cout << "Concessionaria " << nome << endl;
    cout << "Total de Automóveis: " << (int)getConcessionaria()[i].getCarro().size() << "; Valor total: R$ " << valor_carro << endl;
    cout << "Total de Motos: " << (int)getConcessionaria()[i].getMoto().size() << "; Valor total: R$ " << valor_moto << endl;
    cout << "Total de Caminhoes: " << (int)getConcessionaria()[i].getCaminhao().size() << "; Valor total: R$ " << valor_caminhao << endl;
    cout << "Valor total da frota: R$ " << valor_total << endl;
    return " ";
}

//Recebe o nome da concessionaria e a taxa de aumento e retorna uma mensagem de confirmação ou de erro
string Sistema::raise_price(const string nome){
    dados = quebra_string(nome, " ");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "Concessionaria nao encontrada para atualizar";
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getCarro().size(); j++){
      double aumento = getConcessionaria()[i].getCarro()[j].get_preco() * (stof(dados[1])/100);
      getConcessionaria()[i].getCarro()[j].setPreco(aumento + getConcessionaria()[i].getCarro()[j].get_preco());
      cout << "Aumento de " << dados[1] << "\% nos precos de automóveis da concessionaria " << dados[0] << " realizado" << endl;
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getCaminhao().size(); j++){
      double aumento = (getConcessionaria()[i].getCaminhao()[j].get_preco() * (stof(dados[1])/100));
      getConcessionaria()[i].getCaminhao()[j].setPreco(aumento + getConcessionaria()[i].getCaminhao()[j].get_preco());
      cout << "Aumento de " << dados[1] << "\% nos precos de caminhões da concessionaria " << dados[0] << " realizado" << endl;
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getMoto().size(); j++){
      double aumento = (getConcessionaria()[i].getMoto()[j].get_preco() * (stof(dados[1])/100));
      getConcessionaria()[i].getMoto()[j].setPreco(aumento + getConcessionaria()[i].getMoto()[j].get_preco());
      cout << "Aumento de " << dados[1] << "\% nos precos de motos da concessionaria " << dados[0] << " realizado" << endl;
    }

    return "raise-price \n";

}

//Cria o arquivo txt da concessionária recebida e retorna a mensagem de confirmação
string Sistema::save_concessionaria(const string nome){
    dados = quebra_string(nome, ".");
    int i = search_concessionaria(dados[0]);

    if (i == -1){
      return "concessionaria nao encontrada";
    }

    fstream file(nome, ios::out);

    file << "cons:" << getConcessionaria()[i].getNome() << " " << getConcessionaria()[i].getCnpj() << " " << getConcessionaria()[i].getEstoque() << "\n";

    for (int j = 0; j < (int)getConcessionaria()[i].getCarro().size(); j++){
      file << "car:" << getConcessionaria()[i].getNome() << " " << getConcessionaria()[i].getCarro()[j].get_marca() << " " << getConcessionaria()[i].getCarro()[j].get_preco()  << " " << getConcessionaria()[i].getCarro()[j].get_chassi() << " " << getConcessionaria()[i].getCarro()[j].get_ano_de_fabricacao()  << " "<< getConcessionaria()[i].getCarro()[j].getMotor() << "\n";
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getCaminhao().size(); j++){
      file << "truck:" << getConcessionaria()[i].getNome() <<  " " << getConcessionaria()[i].getCaminhao()[j].get_marca() << " " << getConcessionaria()[i].getCaminhao()[j].get_preco() << " " << getConcessionaria()[i].getCaminhao()[j].get_chassi()<< " " << getConcessionaria()[i].getCaminhao()[j].get_ano_de_fabricacao() << " " << getConcessionaria()[i].getCaminhao()[j].getCarga() << "\n";
    }

    for (int j = 0; j < (int)getConcessionaria()[i].getMoto().size(); j++){
      file << "bike:" << getConcessionaria()[i].getNome() << " " << getConcessionaria()[i].getMoto()[j].get_marca() << " " << getConcessionaria()[i].getMoto()[j].get_preco() << " " << getConcessionaria()[i].getMoto()[j].get_chassi() << " " << getConcessionaria()[i].getMoto()[j].get_ano_de_fabricacao() << " " << getConcessionaria()[i].getMoto()[j].getModelo() << "\n";
    }

    return "save-concessionaria";
}

//Recupera os dados do arquivo txt recebido e retorna a mensagem de confirmação
string Sistema::load_concessionaria(const string nome){
    string linha;

    ifstream concessionaria;
    concessionaria.open(nome);

    if(concessionaria.is_open()){      
      while (getline(concessionaria, linha)){
        dados = quebra_string(linha, ":");

        if (dados[0] == "car"){
          add_car(dados[1]);
        }

        else if (dados[0] == "truck"){
          add_truck(dados[1]);
        }

        else if (dados[0] == "bike"){
          add_moto(dados[1]);
        }

        else if(dados[0] == "conc"){
          create_concessionaria(dados[1]);
        }

      } 

    }
    return "load-concessionaria";
}