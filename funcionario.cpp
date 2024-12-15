#include "funcionario.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

// Verifica se um funcionario com o codigo especificado ja existe
bool funcionarioExiste(const vector<Funcionario>& funcionarios, int codigo) {
    for (const auto& funcionario : funcionarios) {
        if (funcionario.codigo == codigo) {
            return true;
        }
    }
    return false;
}

// Carrega os funcionarios a partir de um arquivo binario
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

// Salva os funcionarios em um arquivo binario
void salvarFuncionarios(const vector<Funcionario>& funcionarios) {
    ofstream outfile("funcionarios.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& funcionario : funcionarios) {
            outfile.write(reinterpret_cast<const char*>(&funcionario), sizeof(Funcionario));
        }
        outfile.close();
    }
}

// Cadastra um novo funcionario
void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o codigo do funcionario: ";
    cin >> novoFuncionario.codigo;
    if (funcionarioExiste(funcionarios, novoFuncionario.codigo)) {
        cout << "Erro: Ja existe um funcionario com esse codigo." << endl;
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada
    cout << "Digite o nome do funcionario: ";
    getline(cin, novoFuncionario.nome);
    cout << "Digite o telefone do funcionario: ";
    cin >> novoFuncionario.telefone;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada
    cout << "Digite o cargo do funcionario: ";
    getline(cin, novoFuncionario.cargo);
    cout << "Digite o salario do funcionario: ";
    cin >> novoFuncionario.salario;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

    funcionarios.push_back(novoFuncionario);
    salvarFuncionarios(funcionarios);
    cout << "Funcionario cadastrado com sucesso!" << endl;
}

// Pesquisa um funcionario pelo codigo
void pesquisaFuncionario(const vector<Funcionario>& funcionarios) {
    int codigo;
    cout << "Digite o codigo do funcionario: ";
    cin >> codigo;
    for (const auto& funcionario : funcionarios) {
        if (funcionario.codigo == codigo) {
            cout << "Funcionario encontrado: " << endl;
            cout << "Nome: " << funcionario.nome << endl;
            cout << "Telefone: " << funcionario.telefone << endl;
            cout << "Cargo: " << funcionario.cargo << endl;
            cout << "Salario: " << funcionario.salario << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}