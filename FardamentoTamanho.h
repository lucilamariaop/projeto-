#ifndef FARDAMENTOTAMANHO_H
#define FARDAMENTOTAMANHO_H

class FardamentoTamanho : public Fardamento {
private:
    int qntTamanhos;
    string tamanho;
    string medidas;

public:
    
    FardamentoTamanho();

    // M�todos setters
    void setQntTamanhos(int qntTamanhos);
    void setTamanho(string tamanho);
    void setMedidas(string medidas);

    // M�todos getters
    int getQntTamanhos() const;
    string getTamanho() const;
    string getMedidas() const;
};

#endif 

