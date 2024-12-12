#include "funcionario.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Verifica se um funcionário com o código especificado já existe
bool funcionarioExiste(const vector<Funcionario>& funcionarios, int codigo) {
    for (const auto& funcionario : funcionarios) {
        if (funcionario.codigo == codigo) {
            return true;
        }
    }
    return false;
}

// Carrega os funcionários a partir de um arquivo binário
void carregarFuncionarios(vector<Funcionario>& funcionarios) {
    ifstream infile("funcionarios.bin", ios::binary);
    if (infile.is_open()) {
        Funcionario funcionario;
        while (infile.read(reinterpret_cast<char*>(&funcionario), sizeof(Funcionario))) {
            funcionarios.push_back(funcionario);
        }
        infile.close();
    }
}

// Salva os funcionários em um arquivo binário
void salvarFuncionarios(const vector<Funcionario>& funcionarios) {
    ofstream outfile("funcionarios.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& funcionario : funcionarios) {
            outfile.write(reinterpret_cast<const char*>(&funcionario), sizeof(Funcionario));
        }
        outfile.close();
    }
}

// Cadastra um novo funcionário
void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o código do funcionário: ";
    cin >> novoFuncionario.codigo;
    if (funcionarioExiste(funcionarios, novoFuncionario.codigo)) {
        cout << "Erro: Já existe um funcionário com esse código." << endl;
        return;
    }
    cout << "Digite o nome do funcionário: ";
    cin.ignore();
    getline(cin, novoFuncionario.nome);
    cout << "Digite o telefone do funcionário: ";
    cin >> novoFuncionario.telefone;
    cin.ignore();
    cout << "Digite o cargo do funcionário: ";
    getline(cin, novoFuncionario.cargo);
    cout << "Digite o salário do funcionário: ";
    cin >> novoFuncionario.salario;
    cin.ignore();

    funcionarios.push_back(novoFuncionario);
    salvarFuncionarios(funcionarios);
    cout << "Funcionário cadastrado com sucesso!" << endl;
}

// Pesquisa um funcionário pelo código
void pesquisaFuncionario(const vector<Funcionario>& funcionarios) {
    int codigo;
    cout << "Digite o código do funcionário: ";
    cin >> codigo;
    for (const auto& funcionario : funcionarios) {
        if (funcionario.codigo == codigo) {
            cout << "Funcionário encontrado: " << endl;
            cout << "Nome: " << funcionario.nome << endl;
            cout << "Telefone: " << funcionario.telefone << endl;
            cout << "Cargo: " << funcionario.cargo << endl;
            cout << "Salário: " << funcionario.salario << endl;
            return;
        }
    }
    cout << "Funcionário não encontrado." << endl;
}