#ifndef ESTADIA_H
#define ESTADIA_H

#include <iostream>
#include <string>
using namespace std;

//  Definição da classe Estadia
class Estadia{
public:
    int codigoEstadia;
    string dataEntrada;
    string dataSaida;
    int quantDiaria;
    int codigoCliente;
    int numeroQuarto;
    int codigoFuncionario;
    float valorPago;
};

// Protótipos das funções

//Obrigatório
void cadastrarEstadia();
void baixaEstadia();
float valorMesEstadia();


#endif