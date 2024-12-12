#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definição da classe Funcionario
class Funcionario {
public:
    int codigo;
    string nome;
    int telefone;
    string cargo;
    float salario;
};

// Protótipos das funções
void cadastrarFuncionario(vector<Funcionario>& funcionarios);
void pesquisaFuncionario(const vector<Funcionario>& funcionarios);
void carregarFuncionarios(vector<Funcionario>& funcionarios);
void salvarFuncionarios(const vector<Funcionario>& funcionarios);
bool funcionarioExiste(const vector<Funcionario>& funcionarios, int codigo);

#endif