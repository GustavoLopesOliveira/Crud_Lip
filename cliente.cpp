#include "cliente.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

// Verifica se um cliente com o codigo especificado ja existe
bool clienteExiste(const vector<Cliente>& clientes, int codigo) {
    for (const auto& cliente : clientes) {
        if (cliente.codigo == codigo) {
            return true;
        }
    }
    return false;
}

// Carrega os clientes a partir de um arquivo binario
void carregarClientes(vector<Cliente>& clientes) {
    ifstream infile("clientes.bin", ios::binary);
    if (!infile) {
        cerr << "Erro ao abrir o arquivo de clientes." << endl;
        return;
    }

    Cliente cliente;
    while (infile.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente))) {
        clientes.push_back(cliente);
    }

    infile.close();
    cout << "Clientes carregados: " << clientes.size() << endl;
}

// Salva os clientes em um arquivo binario
void salvarClientes(const vector<Cliente>& clientes) {
    ofstream outfile("clientes.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& cliente : clientes) {
            outfile.write(reinterpret_cast<const char*>(&cliente), sizeof(Cliente));
        }
        outfile.close();
    }
}

// Cadastra um novo cliente
void cadastrarCliente(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "Digite o codigo do cliente: ";
    cin >> novoCliente.codigo;
    if (clienteExiste(clientes, novoCliente.codigo)) {
        cout << "Erro: Ja existe um cliente com esse codigo." << endl;
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada
    cout << "Digite o nome do cliente: ";
    getline(cin, novoCliente.nome);
    cout << "Digite o endereco do cliente: ";
    getline(cin, novoCliente.endereco);
    cout << "Digite o telefone do cliente: ";
    cin >> novoCliente.telefone;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

    clientes.push_back(novoCliente);
    salvarClientes(clientes);
    cout << "Cliente cadastrado com sucesso!" << endl;
}

// Pesquisa um cliente pelo codigo
void pesquisaCliente(const vector<Cliente>& clientes) {
    int codigo;
    cout << "Digite o codigo do cliente: ";
    cin >> codigo;
    for (const auto& cliente : clientes) {
        if (cliente.codigo == codigo) {
            cout << "Cliente encontrado: " << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "Endereco: " << cliente.endereco << endl;
            cout << "Telefone: " << cliente.telefone << endl;
            return;
        }
    }
    cout << "Cliente nao encontrado." << endl;
}

// Lista as estadias de um cliente pelo codigo
void estadiasCliente(const vector<Cliente>& clientes) {
    int codigo;
    cout << "Digite o codigo do cliente: ";
    cin >> codigo;
    for (const auto& cliente : clientes) {
        if (cliente.codigo == codigo) {
            cout << "Cliente encontrado: " << cliente.nome << endl;
            return;
        }
    }
    cout << "Cliente nao encontrado." << endl;
}