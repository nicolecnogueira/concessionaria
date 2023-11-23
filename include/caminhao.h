#indef CAMINHAO_H
#define CAMINHAO_H
#include <string>

class Caminhao : public Veiculo{
    private:
    string carga;

    public:
    //construtor
    Moto(string mar, int pre, string cha, int ano, string car);

    void set_carga();       //recebe o tipo de carga do caminhão
	string get_carga();     //retorna o tipo de carga do caminhão
}