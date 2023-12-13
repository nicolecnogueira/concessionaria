#include "concessionaria.h"
#include "veiculo.h"
#include "carro.h"
#include "moto.h"
#include "caminhao.h"
#include <string>
using std::string;

//CONSTRUTOR
Concessionaria::Concessionaria(string nom, string cnpj, int est){
    setNome(nom);
    setCnpj(cnpj);
    setEstoque(est);
}

//Atribui o nome da concessionaria
void Concessionaria::setNome(string nom){

    nome = nom;
}

//Retorna o nome da concessionaria
string Concessionaria::getNome(){
    return nome;
}

//Atribui o CNPJ da concessionaria
void Concessionaria::setCnpj(string cnpj){
    CNPJ = cnpj;
}

//Retorna o CNPJ da concessionaria
string Concessionaria::getCnpj(){
    return CNPJ;
}

//Atribui a quantidade de veiculos no estoque da concessionária
void Concessionaria::setEstoque(int est){
    estoque = est;
}

//Retorna a quantidade de veiculos no estoque da concessionária
int Concessionaria::getEstoque(){
    return estoque;
}

//Adiciona um novo carro ao vetor
void Concessionaria::setCarro(Carro carro){
    Vcarro.push_back(carro);
}   

//Retorna o vetor carro
vector<Carro> &Concessionaria::getCarro(){
    return Vcarro;
}

//Adiciona um novo caminhão ao vetor
void Concessionaria::setCaminhao(Caminhao caminhao){
    Vcaminhao.push_back(caminhao);
} 

//Retorna o vetor caminhao
vector<Caminhao> &Concessionaria::getCaminhao(){
    return Vcaminhao;
}

//Adiciona uma nova moto ao vetor
void Concessionaria::setMoto(Moto moto){
    Vmoto.push_back(moto);
}   

//Retorna o vetor moto
vector<Moto> &Concessionaria::getMoto(){
    return Vmoto;
}

//Recebe um chassi e retorna o index do carro associado a ele no vetor 
int Concessionaria::indexCar(string chassi){
    auto it = find_if(getCarro().begin(), getCarro().end(), [&chassi] (Carro &car) {return car.get_chassi() == chassi;});

    if (it != getCarro().end()){
        auto index = distance(getCarro().begin(), it);
        return index;
    }

    else{
        return -1;
    }
}

//Recebe um chassi e retorna o index do caminhão associado a ele no vetor
int Concessionaria::indexTruck(string chassi){
    auto it = find_if(getCaminhao().begin(), getCaminhao().end(), [&chassi] (Caminhao &truck) {return truck.get_chassi() == chassi;});

    if (it != getCaminhao().end()){
        auto index = distance(getCaminhao().begin(), it);
        return index;
    }

    else{
        return -1;
    }

}

//Recebe um chassi e retorna o index da moto associada a ele no vetor
int Concessionaria::indexMoto(string chassi){
    auto it = find_if(getMoto().begin(), getMoto().end(), [&chassi] (Moto &moto) {return moto.get_chassi() == chassi;});

    if (it != getMoto().end()){
        auto index = distance(getMoto().begin(), it);
        return index;
    }

    else{
        return -1;
    }

}

//Recebe um chassi e retorna verdadeiro se estiver em algum vetor ou falso se não estiver
bool Concessionaria::search_vehicle(string chassi){
    if(indexCar(chassi) != -1){
        getCarro().at(indexCar(chassi)).print_carro();
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

//Recebe o chassi do veiculo que será removido e retorna verdadeiro se for removido ou falso de não for
bool Concessionaria::remove_vehicle(string chassi){
    if(indexCar(chassi) != -1){
        getCarro().erase(getCarro().begin() + indexCar(chassi));
    }

    else if (indexTruck(chassi) != -1){
        getCaminhao().erase(getCaminhao().begin() + indexTruck(chassi));
    }

    else if (indexMoto(chassi) != -1){
        getMoto().erase(getMoto().begin() + indexMoto(chassi));
    }

    return false;  
}