#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

// Definição da classe Cliente
class Cliente {
public:
    int codigo;
    string nome;
    string endereco;
    int telefone;
};


// Protótipos das funções
void cadastrarCliente();
void pesquisaCliente();
void estadiasCliente();

#endif
