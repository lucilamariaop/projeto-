#include "FardamentoTamanho.h"

FardamentoTamanho::FardamentoTamanho() {
    qntTamanhos = 0;
    tamanho = "";
    medidas = "";
}

// Métodos setters
void FardamentoTamanho::setQntTamanhos(int qntTamanhos) {
    this->qntTamanhos = qntTamanhos;
}

void FardamentoTamanho::setTamanho(string tamanho) {
    this->tamanho = tamanho;
}

void FardamentoTamanho::setMedidas(string medidas) {
    this->medidas = medidas;
}

// Métodos getters
int FardamentoTamanho::getQntTamanhos() const {
    return qntTamanhos;
}

string FardamentoTamanho::getTamanho() const {
    return tamanho;
}

string FardamentoTamanho::getMedidas() const {
    return medidas;
}

