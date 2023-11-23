#include "concessionaria.h"
#include "veiculo.h"
#include "carro.h"
#include "moto.h"
#include "caminhao.h"
#include <string>
using std::string;

//CONSTRUTOR
//recebe os dados da concessionaria
Concessionaria::Concessionaria(string nom, string cnpj, int est){
    set_nome(nom);
    set_cnpj(cnpj);
    set_estoque(est);
}

//retorna o vetor de carros
vector<Carro> &Concessionaria::get_carro(){
    return Vcarro;
}

//retorna o vetor de motos
vector<Moto> &Concessionaria::get_moto(){
    return Vmoto;
}

//retorna o vetor de caminhões
vector<Caminhao> &Concessionaria::get_caminhao(){
    return Vcaminhao;
}

//adiciona um novo carro ao vetor
void Concessionaria::set_carro(Carro carro){
    Vcarro.push_back(carro);
}   

//adiciona uma nova moto ao vetor
void Concessionaria::set_moto(Moto moto){
    Vmoto.push_back(moto);
} 

//adiciona um novo caminhão ao vetor
void Concessionaria::set_caminhao(Caminhao caminhao){
    Vcaminhao.push_back(caminhao);
}   

//retorna o nome da concessionaria
string Concessionaria::get_nome(){
    return nome;
}

//retorna o cnpj da concessionaria
string Concessionaria::get_CNPJ(){
    return CNPJ;
}

//retorna a quantidade de veiculos no estoque
int Concessionaria::get_estoque(){
    return estoque;
}

//altera o nome da concessionaria
void Concessionaria::set_nome(string nom){
    nome = nom;
}

//altera o cnpj da concessionaria
void Concessionaria::set_CNPJ(string cnpj){
    CNPJ = cnpj;
}

//altera o número de veiculos no estoque
void Concessionaria::set_estoque(int est){
    estoque = est;
}

//recebe um chassi e retorna posição do vetor onde está o carro associado a tal chassi
int Concessionaria::index_carro(string chassi){
    auto it = find_if(get_carro().begin(), get_carro().end(), [&chassi] (Carro &carro) {return carro.get_chassi() == chassi;});

    if (it != get_carro().end()){
        auto index = distance(get_carro().begin(), it);
        return index;
    }

    else{
        return -1;
    }
}

//recebe um chassi e retorna posição do vetor onde está a moto associado a tal chassi
int Concessionaria::index_moto(string chassi){
    auto it = find_if(get_moto().begin(), get_moto().end(), [&chassi] (Moto &moto) {return moto.get_chassi() == chassi;});

    if (it != get_moto().end()){
        auto index = distance(get_moto().begin(), it);
        return index;
    }

    else{
        return -1;
    }  
}

//recebe um chassi e retorna posição do vetor onde está o caminhao associado a tal chassi
int Concessionaria::indexTruck(string chassi){
    auto it = find_if(get_caminhao().begin(), get_caminhao().end(), [&chassi] (Caminhao &caminhao) {return caminhao.get_chassi() == chassi;});

    if (it != get_caminhao().end()){
        auto index = distance(get_caminhao().begin(), it);
        return index;
    }

    else{
        return -1;
    }
}

//recebe um chassi e retorna verdadeiro, se o veículo pertencer a concessionária, ou falso, se não pertencer
bool Concessionaria::search_vehicle(string chassi)
{
    if(indexCar(chassi) != -1){
        getAutomoveis().at(indexCar(chassi)).print_carro();
        return true;
    }

    else if (indexTruck(chassi) != -1){
        getCaminhao().at(indexTruck(chassi)).print_caminhao();
        return true;
    }

    else if (indexMoto(chassi) != -1){
        getMoto().at(indexMoto(chassi)).print_Moto();
        return true;
    }

    return false;
}

//recebe um chassi e remove o veículo associado a ele
void Concessionaria::remover_veiculo(string chassi){
    if(index_carro(chassi) != -1){
        get_carro().erase(get_carro().begin() + index_carro(chassi));
    }

    else if (index_moto(chassi) != -1){
        get_moto().erase(get_moto().begin() + index_moto(chassi));
    }

    else if (index_caminhao(chassi) != -1){
        get_caminhao().erase(get_caminhao().begin() + index_caminhao(chassi));
    }
}