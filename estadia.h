#ifndef ESTADIA_H
#define ESTADIA_H

#include <iostream>
#include <string>
#include <vector>
#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"

using namespace std;

// Definição da classe Estadia
class Estadia {
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

const float VALOR_DIARIA_POR_PESSOA = 350.0;

// Protótipos das funções
void cadastrarEstadia(vector<Estadia>& estadias, const vector<Cliente>& clientes, const vector<Funcionario>& funcionarios, const vector<Quarto>& quartos);
void baixaEstadia(const vector<Estadia>& estadias);
float valorMesEstadia(const vector<Estadia>& estadias);
void carregarEstadias(vector<Estadia>& estadias);
void salvarEstadias(const vector<Estadia>& estadias);

#endif