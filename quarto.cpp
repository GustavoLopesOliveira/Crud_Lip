#include "quarto.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Verifica se um quarto com o numero especificado ja existe
bool quartoExiste(const vector<Quarto>& quartos, int numero) {
    for (const auto& quarto : quartos) {
        if (quarto.numeroQuarto == numero) {
            return true;
        }
    }
    return false;
}

// Carrega os quartos a partir de um arquivo binario
void carregarQuartos(vector<Quarto>& quartos) {
    ifstream infile("quartos.bin", ios::binary);
    if (infile.is_open()) {
        Quarto quarto;
        while (infile.read(reinterpret_cast<char*>(&quarto), sizeof(Quarto))) {
            quartos.push_back(quarto);
        }
        infile.close();
    }
}

// Salva os quartos em um arquivo binario
void salvarQuartos(const vector<Quarto>& quartos) {
    ofstream outfile("quartos.bin", ios::binary | ios::trunc);
    if (outfile.is_open()) {
        for (const auto& quarto : quartos) {
            outfile.write(reinterpret_cast<const char*>(&quarto), sizeof(Quarto));
        }
        outfile.close();
    }
}

// Cadastra um novo quarto
void cadastrarQuarto(vector<Quarto>& quartos) {
    Quarto novoQuarto;
    cout << "Digite o numero do quarto: ";
    cin >> novoQuarto.numeroQuarto;
    if (quartoExiste(quartos, novoQuarto.numeroQuarto)) {
        cout << "Erro: Ja existe um quarto com esse numero." << endl;
        return;
    }
    cout << "Digite a quantidade de hospedes: ";
    cin >> novoQuarto.quatHospede;
    cout << "Digite o valor da diaria: ";
    cin >> novoQuarto.valorDiaria;
    cin.ignore();

    quartos.push_back(novoQuarto);
    salvarQuartos(quartos);
    cout << "Quarto cadastrado com sucesso!" << endl;
}