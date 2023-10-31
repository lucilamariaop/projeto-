#include "Carrinho.h"----

Carrinho::Carrinho(){
	cpf_cliente = "";
}
Carrinho::Carrinho(string cpf_cliente) {
    this->cpf_cliente = cpf_cliente;
}

Carrinho::~Carrinho() {}

void Carrinho::setCpf_Cliente(string cpf_cliente) {
    this->cpf_cliente = cpf_cliente;
}

string Carrinho::getCpf_Cliente() {
    return cpf_cliente;
}

void Carrinho::add_unidade(FardamentoUnidade fardamentoUnidade) {
    carrinho_unidade.push_back(fardamentoUnidade);
}

void Carrinho::add_tamanho(FardamentoTamanho fardamentoTamanho) {
    carrinho_tamanho.push_back(fardamentoTamanho);
}

void Carrinho::remove_unidade(int codigo) {
    for (size_t i = 0; i < carrinho_unidade.size(); ++i) {
        if (carrinho_unidade[i].getCodigo() == codigo) {
            carrinho_unidade.erase(carrinho_unidade.begin() + i);
            cout << "Produto removido do carrinho!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado no carrinho!" << endl;
}

void Carrinho::remove_tamanho(int codigo) {
    for (size_t i = 0; i < carrinho_tamanho.size(); ++i) {
        if (carrinho_tamanho[i].getCodigo() == codigo) {
            carrinho_tamanho.erase(carrinho_tamanho.begin() + i);
            cout << "Produto removido do carrinho!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado no carrinho!" << endl;
}

void Carrinho::visualizarCarrinho() {
    cout << "Produtos por Unidade no Carrinho:" << endl;
    for (const auto& item : carrinho_unidade) {
        cout << "Nome: " << item.getNome() << ", Código: " << item.getCodigo() << endl;
    }

    cout << "Produtos por Tamanho no Carrinho:" << endl;
    for (const auto& item : carrinho_tamanho) {
        cout << "Nome: " << item.getNome() << ", Código: " << item.getCodigo() << endl;
    }
}

float Carrinho::obterValorTotal() {
    float total = 0.0f;
    
    for (const auto& item : carrinho_unidade) {
        total += item.getPreco();
    }
    
    for (const auto& item : carrinho_tamanho) {
        total += item.getPreco();
    }
    
    return total;
}

void Carrinho::finalizarCompra() {
    bool estoqueSuficiente = true;

    for (const auto& item : carrinho_unidade) {
        if (!estoque.verificarQuantidadeUnidade(item.getCodigo(), item.getQntUnidades())) {
            estoqueSuficiente = false;
            break;
        }
    }

    for (const auto& item : carrinho_tamanho) {
        if (!estoque.verificarQuantidadeTamanho(item.getCodigo(), item.getQntTamanhos())) {
            estoqueSuficiente = false;
            break;
        }
    }

    if (estoqueSuficiente) {
        for (const auto& item : carrinho_unidade) {
            estoque.venderFardamentoUnidade(to_string(item.getCodigo()), item.getQntUnidades());
        }
        
        for (const auto& item : carrinho_tamanho) {
            estoque.venderFardamentoTamanho(to_string(item.getCodigo()), item.getQntTamanhos());
        }

        carrinho_unidade.clear();
        carrinho_tamanho.clear();

        cout << "Compra finalizada com sucesso!" << endl;
    } else {
        cout << "Estoque insuficiente para completar a compra. Por favor, revise o carrinho." << endl;
    }
}

