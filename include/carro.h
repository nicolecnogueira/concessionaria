#indef CARRO_H
#define CARRO_H
#include <iostream>
#include <string>

class Carro : public Veiculo{
    private:
    string motor;

    public:
    //construtor
    Carro(string mar, int pre, string cha, int ano, string mot);

    void set_motor();       //recebe o tipo de motor do carro
    string get_motor();     //retorna o tipo de motor do carro
}