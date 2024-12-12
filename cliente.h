#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cliente {
public:
    int codigo;
    string nome;
    string endereco;
    int telefone;
};

void cadastrarCliente(vector<Cliente>& clientes);
void pesquisaCliente(const vector<Cliente>& clientes);
void estadiasCliente(const vector<Cliente>& clientes);
void carregarClientes(vector<Cliente>& clientes);
void salvarClientes(const vector<Cliente>& clientes);
bool clienteExiste(const vector<Cliente>& clientes, int codigo);

#endif