#include "FardamentoUnidade.h"

// Construtor
FardamentoUnidade::FardamentoUnidade() {
    qntUnidades = 0;
    tipo = "";
}

void FardamentoUnidade::setQntUnidades(int qntUnidades) {
    this->qntUnidades = qntUnidades;
}

int FardamentoUnidade::getQntUnidades() const {
    return qntUnidades;
}

void FardamentoUnidade::setTipo(const string& tipo) {
    this->tipo = tipo;
}

string FardamentoUnidade::getTipo() const {
    return tipo;
}
