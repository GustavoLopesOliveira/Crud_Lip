#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
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

//Protótipos das funções
void cadastrarFuncionario();
void pesquisaFuncionario();

#endif