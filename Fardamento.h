#ifndef FARDAMENTO_H
#define FARDAMENTO_H

class Fardamento {
private:
    string nome;
    int codigo;
    float preco;

public:
    // Construtor
    Fardamento();

    void setNome(const string& nome);
    string getNome() const;

    void setCodigo(int codigo);
    int getCodigo() const;

    void setPreco(float preco);
    float getPreco() const;
};

#endif
