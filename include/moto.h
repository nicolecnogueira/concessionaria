#indef MOTO_H
#define MOTO_H
#include <string>

class Moto : public Veiculo{
    private:
    string modelo;

    public:
    //construtor
    Moto(string mar, int pre, string cha, int ano, string mod);

    void set_modelo();          //recebe o modelo da moto
	string get_modelo();        //retorna o modelo da moto
}