#ifndef QUARTO_H
#define QUARTO_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definicao da classe Quarto
class Quarto {
public:
    int numeroQuarto;
    int quatHospede;
    int valorDiaria;
};

// Prototipos das funcoes
void cadastrarQuarto(vector<Quarto>& quartos);
void carregarQuartos(vector<Quarto>& quartos);
void salvarQuartos(const vector<Quarto>& quartos);
bool quartoExiste(const vector<Quarto>& quartos, int numero);

#endif