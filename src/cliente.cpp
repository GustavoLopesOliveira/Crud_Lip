#include "cliente.h"
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

vector<Cliente> clientes;

void cadastrarCliente() {
    // Cria um novo cliente
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

    // Adiciona o cliente no .bin
    FILE *arquivo = fopen("clientes.bin", "ab");
    if (arquivo == nullptr) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    fwrite(&novoCliente.codigo, sizeof(novoCliente.codigo), 1, arquivo);
    size_t nomeLength = novoCliente.nome.size();
    fwrite(&nomeLength, sizeof(nomeLength), 1, arquivo);
    fwrite(novoCliente.nome.c_str(), sizeof(char), nomeLength, arquivo);
    size_t enderecoLength = novoCliente.endereco.size();
    fwrite(&enderecoLength, sizeof(enderecoLength), 1, arquivo);
    fwrite(novoCliente.endereco.c_str(), sizeof(char), enderecoLength, arquivo);
    fwrite(&novoCliente.telefone, sizeof(novoCliente.telefone), 1, arquivo);

    fclose(arquivo);

    cout << "Cliente cadastrado com sucesso!" << endl;
}