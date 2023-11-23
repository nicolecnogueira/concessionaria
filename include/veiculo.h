#indef VEICULO_H
#define VEICULO_H
#include <string>


class Veiculo{
    protected:
    string marca;
    int preço;
    string chassi;
    int ano_de_fabricaçao;

    public:
    //CONSTRUTOR
    Veiculo();

    void set_marca(string mar);             //recebe a marca do veiculo
    void set_preço(int pre);                //recebe o preço do veiculo
    void set_chassi(string cha);            //recebe o chassi do veiculo
    void set_ano_de_fabricaçao(int ano);        //recebe o ano de fabricaçao do veiculo

    string get_marca();             //retorna a marca do veiculo
    int get_preço();                //retorna o preço do veiculo
    string get_chassi();            //retorna o chassi do veiculo
    int get_ano_de_fabricaçao();    //retorna o ano de fabricaçao do veiculo
}