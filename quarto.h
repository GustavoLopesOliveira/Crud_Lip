#ifndef QUARTO_H
#define QUARTO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definição da classe Quarto
class Quarto {
public:
    int numeroQuarto;
    int quatHospede;
    float valorDiaria;
};

// Protótipos das funções
void cadastrarQuarto(vector<Quarto>& quartos);
void carregarQuartos(vector<Quarto>& quartos);
void salvarQuartos(const vector<Quarto>& quartos);
bool quartoDisponivel(const vector<Quarto>& quartos, int quatHospede, int& numeroQuarto);

#endif