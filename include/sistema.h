#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "concessionaria.h"


// Sistema deve concentrar todas as operações
class Sistema {
  private:
		std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		std::string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/
		std::string create_concessionaria (const std::string nome);

		//adiciona um novo carro		
		std::string add_car(const std::string nome);

		//adiciona uma nova moto
		std::string add_bike(const std::string nome);

		//adiciona um novo caminhao
		std::string add_truck(const std::string nome);
		
		//remove um veículo
		std::string remove_vehicle(const std::string chassi);
};

#endif
