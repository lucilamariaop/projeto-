#include "Fardamento.h"

// Construtor
Fardamento::Fardamento() {
    nome = "";
    codigo = 0;
    preco = 0.0;
}

void Fardamento::setNome(const std::string& nome) {
    this->nome = nome;
}

string Fardamento::getNome() const {
    return nome;
}

void Fardamento::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Fardamento::getCodigo() const {
    return codigo;
}

void Fardamento::setPreco(float preco) {
    this->preco = preco;
}

float Fardamento::getPreco() const {
    return preco;
}
