#include "estadia.h"
#include "funcionario.h"
#include "cliente.h"
#include "quarto.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<Cliente> clientes;
vector<Funcionario> funcionarios;
vector<Quarto> quartos;
vector<Estadia> estadias;

void carregarDados() {
    carregarClientes(clientes);
    carregarFuncionarios(funcionarios);
    carregarQuartos(quartos);
    carregarEstadias(estadias);
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
        cout << "0 - Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cadastrarEstadia(estadias, clientes, funcionarios, quartos);
                break;
            case 2:
                baixaEstadia(estadias);
                break;
            case 3:
                cout << "Valor mensal de estadia: " << valorMesEstadia(estadias) << endl;
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
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while(opcao != 0);
    return 0;
}