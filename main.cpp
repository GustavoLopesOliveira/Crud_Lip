#include "estadia.h"
#include "funcionario.h"
#include "cliente.h"
#include "quarto.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> // Para a função remove

using namespace std;

vector<Cliente> clientes;
vector<Funcionario> funcionarios;
vector<Quarto> quartos;
vector<Estadia> estadias;

// Carrega todos os dados necessarios
void carregarDados() {
    cout << "Carregando dados..." << endl;
    carregarClientes(clientes);
    cout << "Clientes carregados: " << clientes.size() << endl;
    carregarFuncionarios(funcionarios);
    cout << "Funcionarios carregados: " << funcionarios.size() << endl;
    carregarQuartos(quartos);
    cout << "Quartos carregados: " << quartos.size() << endl;
    carregarEstadias(estadias);
    cout << "Estadias carregadas: " << estadias.size() << endl;
    cout << "Dados carregados com sucesso!" << endl;
}

// Limpa todos os dados
void limparDados(vector<Cliente>& clientes, vector<Funcionario>& funcionarios, vector<Quarto>& quartos, vector<Estadia>& estadias) {
    clientes.clear();
    funcionarios.clear();
    quartos.clear();
    estadias.clear();

    remove("clientes.bin");
    remove("funcionarios.bin");
    remove("quartos.bin");
    remove("estadias.bin");

    cout << "Todos os dados foram limpos!" << endl;
}

// Limpa todos os dados de funcionarios
void limparFuncionarios(vector<Funcionario>& funcionarios) {
    funcionarios.clear();
    remove("funcionarios.bin");
    cout << "Todos os funcionarios foram limpos!" << endl;
}

// Limpa todos os dados de clientes
void limparClientes(vector<Cliente>& clientes) {
    clientes.clear();
    remove("clientes.bin");
    cout << "Todos os clientes foram limpos!" << endl;
}

int main() {
    carregarDados();
    int opcao;
    do {
        cout << "1 - Cadastrar Estadia" << endl;
        cout << "2 - Baixa Estadia" << endl;
        cout << "3 - Valor Mensal de Estadia" << endl;
        cout << "4 - Cadastrar Funcionario" << endl;
        cout << "5 - Pesquisar Funcionario" << endl;
        cout << "6 - Cadastrar Cliente" << endl;
        cout << "7 - Pesquisar Cliente" << endl;
        cout << "8 - Estadias do Cliente" << endl;
        cout << "9 - Cadastrar Quarto" << endl;
        cout << "10 - Limpar todos os dados" << endl;
        cout << "11 - Limpar todos os funcionarios" << endl;
        cout << "12 - Limpar todos os clientes" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                cadastrarEstadia(estadias, clientes, funcionarios, quartos);
                break;
            case 2:
                baixaEstadia(estadias);
                break;
            case 3:
                cout << "Valor mensal das estadias: " << valorMesEstadia(estadias) << endl;
                break;
            case 4:
                cadastrarFuncionario(funcionarios);
                break;
            case 5:
                pesquisaFuncionario(funcionarios);
                break;
            case 6:
                cadastrarCliente(clientes);
                break;
            case 7:
                pesquisaCliente(clientes);
                break;
            case 8:
                estadiasCliente(clientes);
                break;
            case 9:
                cadastrarQuarto(quartos);
                break;
            case 10:
                limparDados(clientes, funcionarios, quartos, estadias);
                break;
            case 11:
                limparFuncionarios(funcionarios);
                break;
            case 12:
                limparClientes(clientes);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);
    return 0;
}