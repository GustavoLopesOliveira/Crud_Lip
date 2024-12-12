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

bool quartoDisponivel(const vector<Quarto>& quartos, int quatHospede, int& numeroQuarto) {
    for (const auto& quarto : quartos) {
        if (quarto.quatHospede >= quatHospede) {
            numeroQuarto = quarto.numeroQuarto;
            return true;
        }
    }
    return false;
}

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

void salvarEstadias(const vector<Estadia>& estadias) {
    ofstream outfile("estadias.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& estadia : estadias) {
            outfile.write(reinterpret_cast<const char*>(&estadia), sizeof(Estadia));
        }
        outfile.close();
    }
}

void cadastrarEstadia(vector<Estadia>& estadias, const vector<Cliente>& clientes, const vector<Funcionario>& funcionarios, const vector<Quarto>& quartos) {
    Estadia novaEstadia;
    cout << "Digite o código do cliente: ";
    cin >> novaEstadia.codigoCliente;
    if (!clienteExiste(clientes, novaEstadia.codigoCliente)) {
        cout << "Erro: Cliente não encontrado." << endl;
        return;
    }
    cout << "Digite a quantidade de hóspedes: ";
    int quatHospede;
    cin >> quatHospede;
    if (!quartoDisponivel(quartos, quatHospede, novaEstadia.numeroQuarto)) {
        cout << "Erro: Não há quartos disponíveis para essa quantidade de hóspedes." << endl;
        return;
    }
    cout << "Digite a data de entrada (dd/mm/aaaa): ";
    cin >> novaEstadia.dataEntrada;
    cout << "Digite a data de saída (dd/mm/aaaa): ";
    cin >> novaEstadia.dataSaida;
    cout << "Digite o código do funcionário que está fazendo a reserva: ";
    cin >> novaEstadia.codigoFuncionario;
    if (!funcionarioExiste(funcionarios, novaEstadia.codigoFuncionario)) {
        cout << "Erro: Funcionário não encontrado." << endl;
        return;
    }

    // Calcular quantidade de diárias
    // Supondo que as datas estão no formato dd/mm/aaaa
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

    estadias.push_back(novaEstadia);
    salvarEstadias(estadias);
    cout << "Estadia cadastrada com sucesso!" << endl;
}

void baixaEstadia(const vector<Estadia>& estadias) {
    int codigoCliente;
    cout << "Digite o código do cliente: ";
    cin >> codigoCliente;
    float total = 0.0;
    for (const auto& estadia : estadias) {
        if (estadia.codigoCliente == codigoCliente) {
            total += estadia.quantDiaria * estadia.valorPago;
        }
    }
    cout << "Total a ser pago pelo cliente: " << total << endl;
}

float valorMesEstadia(const vector<Estadia>& estadias) {
    float valorTotal = 0.0;
    for (const auto& estadia : estadias) {
        valorTotal += estadia.quantDiaria * estadia.valorPago;
    }
    return valorTotal;
}