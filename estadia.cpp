#include "estadia.h"
#include "cliente.h"
#include "quarto.h"
#include "funcionario.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

// Carrega as estadias a partir de um arquivo binario
void carregarEstadias(vector<Estadia>& estadias) {
    ifstream infile("estadias.bin", ios::binary);
    if (infile.is_open()) {
        Estadia estadia;
        while (infile.read(reinterpret_cast<char*>(&estadia), sizeof(Estadia))) {
            estadias.push_back(estadia);
        }
        infile.close();
    }
}

// Salva as estadias em um arquivo binario
void salvarEstadias(const vector<Estadia>& estadias) {
    ofstream outfile("estadias.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& estadia : estadias) {
            outfile.write(reinterpret_cast<const char*>(&estadia), sizeof(Estadia));
        }
        outfile.close();
    }
}

// Cadastra uma nova estadia
void cadastrarEstadia(vector<Estadia>& estadias, const vector<Cliente>& clientes, const vector<Funcionario>& funcionarios, const vector<Quarto>& quartos) {
    Estadia novaEstadia;
    cout << "Digite o codigo do cliente: ";
    cin >> novaEstadia.codigoCliente;
    cout << "Digite a quantidade de hospedes: ";
    int quatHospede;
    cin >> quatHospede;
    if (quatHospede > 3) {
        cout << "Erro: A quantidade maxima de hospedes por quarto e 3." << endl;
        return;
    }
    if (!quartoDisponivel(quartos, quatHospede, novaEstadia.numeroQuarto)) {
        cout << "Erro: Nao ha quartos disponiveis para essa quantidade de hospedes." << endl;
        return;
    }
    cout << "Digite a data de entrada (dd/mm/aaaa): ";
    cin >> novaEstadia.dataEntrada;
    cout << "Digite a data de saida (dd/mm/aaaa): ";
    cin >> novaEstadia.dataSaida;
    cout << "Digite o codigo do funcionario que esta fazendo a reserva: ";
    cin >> novaEstadia.codigoFuncionario;
    if (!funcionarioExiste(funcionarios, novaEstadia.codigoFuncionario)) {
        cout << "Erro: Funcionario nao encontrado." << endl;
        return;
    }

    struct tm entrada = {0}, saida = {0};
    sscanf(novaEstadia.dataEntrada.c_str(), "%d/%d/%d", &entrada.tm_mday, &entrada.tm_mon, &entrada.tm_year);
    sscanf(novaEstadia.dataSaida.c_str(), "%d/%d/%d", &saida.tm_mday, &saida.tm_mon, &saida.tm_year);
    entrada.tm_mon -= 1;
    saida.tm_mon -= 1;
    entrada.tm_year -= 1900;
    saida.tm_year -= 1900;
    time_t entradaTime = mktime(&entrada);
    time_t saidaTime = mktime(&saida);
    novaEstadia.quantDiaria = difftime(saidaTime, entradaTime) / (60 * 60 * 24);

    novaEstadia.valorPago = novaEstadia.quantDiaria * quatHospede * VALOR_DIARIA_POR_PESSOA;

    estadias.push_back(novaEstadia);
    salvarEstadias(estadias);
    cout << "Estadia cadastrada com sucesso!" << endl;
}

// Calcula o total a ser pago pelo cliente
void baixaEstadia(const vector<Estadia>& estadias) {
    int codigoCliente;
    cout << "Digite o codigo do cliente: ";
    cin >> codigoCliente;
    float total = 0.0;
    for (const auto& estadia : estadias) {
        if (estadia.codigoCliente == codigoCliente) {
            total += estadia.valorPago;
        }
    }
    cout << "Total a ser pago pelo cliente: " << total << endl;
}

// Calcula o valor total das estadias no mes
float valorMesEstadia(const vector<Estadia>& estadias) {
    float valorTotal = 0.0;
    for (const auto& estadia : estadias) {
        valorTotal += estadia.valorPago;
    }
    return valorTotal;
}