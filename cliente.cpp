#include "cliente.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool clienteExiste(const vector<Cliente>& clientes, int codigo) {
    for (const auto& cliente : clientes) {
        if (cliente.codigo == codigo) {
            return true;
        }
    }
    return false;
}

void carregarClientes(vector<Cliente>& clientes) {
    ifstream infile("clientes.bin", ios::binary);
    if (infile.is_open()) {
        Cliente cliente;
        while (infile.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente))) {
            clientes.push_back(cliente);
        }
        infile.close();
    }
}

void salvarClientes(const vector<Cliente>& clientes) {
    ofstream outfile("clientes.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& cliente : clientes) {
            outfile.write(reinterpret_cast<const char*>(&cliente), sizeof(Cliente));
        }
        outfile.close();
    }
}

void cadastrarCliente(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "Digite o código do cliente: ";
    cin >> novoCliente.codigo;
    if (clienteExiste(clientes, novoCliente.codigo)) {
        cout << "Erro: Já existe um cliente com esse código." << endl;
        return;
    }
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, novoCliente.nome);
    cout << "Digite o endereço do cliente: ";
    getline(cin, novoCliente.endereco);
    cout << "Digite o telefone do cliente: ";
    cin >> novoCliente.telefone;
    cin.ignore();

    clientes.push_back(novoCliente);
    salvarClientes(clientes);
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void pesquisaCliente(const vector<Cliente>& clientes) {
    int codigo;
    cout << "Digite o código do cliente: ";
    cin >> codigo;
    for (const auto& cliente : clientes) {
        if (cliente.codigo == codigo) {
            cout << "Cliente encontrado: " << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "Endereço: " << cliente.endereco << endl;
            cout << "Telefone: " << cliente.telefone << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

void estadiasCliente(const vector<Cliente>& clientes) {
    int codigo;
    cout << "Digite o código do cliente: ";
    cin >> codigo;
    for (const auto& cliente : clientes) {
        if (cliente.codigo == codigo) {
            cout << "Cliente encontrado: " << cliente.nome << endl;
            // Aqui você deve acessar as estadias do cliente
            // Supondo que você tenha uma função para listar estadias
            // listarEstadiasCliente(cliente.codigo);
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}