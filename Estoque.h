
#ifndef ESTOQUE_H
#define ESTOQUE_H

class Estoque {
private:
    vector<FardamentoUnidade> unidades;
    vector<FardamentoTamanho> tamanhos;
    string senhaAcesso;

public:
    Estoque();
    ~Estoque();

    void gravarUnidades();
    void gravarTamanhos();
    void lerUnidades();
    void lerTamanhos();

    bool adicionarUnidade(const FardamentoUnidade&);
    bool adicionarTamanho(const FardamentoTamanho&);
    bool removerUnidade(const string& tipo);
    bool removerTamanho(const string& medida);

    FardamentoUnidade buscarUnidadePorTipo(const string&);
    FardamentoTamanho buscarTamanhoPorMedida(const string&);

    void exibirTodasUnidades();
    void exibirTodosTamanhos();

    void setSenhaAcesso(const string& senha);
    string getSenhaAcesso() const;

    bool verificarQuantidadeUnidade(int codigo, int quantidade);
    bool verificarQuantidadeTamanho(int codigo, int quantidade);

		
    void venderFardamentoUnidade(const string& tipo, int quantidade);
    void venderFardamentoTamanho(const string& medida, int quantidade);

    void ordenarUnidades();
    void ordenarTamanhos();
    void reabastecerFardamentoUnidade(const string& tipo, int quantidade);
    void reabastecerFardamentoTamanho(const string& medida, int quantidade);
};

#endif // ESTOQUE_H



