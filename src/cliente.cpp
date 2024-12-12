#include "cliente.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<Cliente> clientes;

void cadastrarCliente() {
    Cliente novoCliente;
    cout << "Digite o código do cliente: ";
    cin >> novoCliente.codigo;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, novoCliente.nome);
    cout << "Digite o endereço do cliente: ";
    getline(cin, novoCliente.endereco);
    cout << "Digite o telefone do cliente: ";
    cin >> novoCliente.telefone;
    cin.ignore();

    clientes.push_back(novoCliente);
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void listarClientes() {
    cout << "Lista de Clientes:" << endl;
    for (int i = 0; i < clientes.size(); ++i) {
        cout << "Código: " << clientes[i].codigo << endl;
        cout << "Nome: " << clientes[i].nome << endl;
        cout << "Endereço: " << clientes[i].endereco << endl;
        cout << "Telefone: " << clientes[i].telefone << endl;
        cout << "-------------------------" << endl;
    }
}