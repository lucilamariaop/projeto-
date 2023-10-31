#ifndef FARDAMENTOUNIDADE_H
#define FARDAMENTOUNIDADE_H

class FardamentoUnidade : public Fardamento {
private:
    int qntUnidades;
    string tipo;

public:
    // Construtor
    FardamentoUnidade();

    void setQntUnidades(int qntUnidades);
    int getQntUnidades() const;

    void setTipo(const string& tipo);
    string getTipo() const;
};

#endif
