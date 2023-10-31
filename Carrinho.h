#ifndef CARRINHO_H
#define CARRINHO_H

class Carrinho {
private:
    vector<FardamentoUnidade> carrinho_unidade;
    vector<FardamentoTamanho> carrinho_tamanho;
    string cpf_cliente;
    Estoque estoque;

public:
    Carrinho();
    Carrinho(string cpf_cliente);
    ~Carrinho();
    void setCpf_Cliente(string cpf_cliente);
    string getCpf_Cliente();
	void add_unidade(FardamentoUnidade);
    void add_tamanho(FardamentoTamanho);
    void remove_unidade(int codigo);
    void remove_tamanho(int codigo);
    void visualizarCarrinho();
    float obterValorTotal();
    void finalizarCompra();
};

#endif

