#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definição da classe Cliente
class Cliente {
public:
    int codigo;
    string nome;
    string endereco;
    string telefone;
};

// Protótipos das funções
void carregarClientes(vector<Cliente>& clientes);
void salvarClientes(const vector<Cliente>& clientes);
void cadastrarCliente(vector<Cliente>& clientes);
void pesquisaCliente(const vector<Cliente>& clientes);
void estadiasCliente(const vector<Cliente>& clientes);

#endif