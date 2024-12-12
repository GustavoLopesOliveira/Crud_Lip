#include "include/estadia.h"
#include "include/funcionario.h"
#include "include/cliente.h"
#include "include/quarto.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    int opcao;
    
    do{
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
        switch(opcao){
            case 1:
                cadastrarEstadia();
                break;
            case 2:
                baixaEstadia();
                break;
            case 3:
                valorMesEstadia();
                break;
            case 4:
                cadastrarFuncionario();
                break;
            case 5:
                pesquisaFuncionario();
                break;
            case 6:
                cadastrarCliente();
                break;
            case 7:
                pesquisaCliente();
                break;
            case 8:
                estadiasCliente();
                break;
            case 9:
                cadastrarQuarto();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }while(opcao != 0);
    return 0;
}

