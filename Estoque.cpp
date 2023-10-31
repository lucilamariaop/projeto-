#include "Estoque.h"


Estoque::Estoque() { 
  
}

void Estoque::gravarUnidades() {
    ofstream arquivo("unidades.txt", ios::app);
    if (arquivo.is_open()) {
        for (const auto& unidade : unidades) {
            arquivo << unidade.getTipo() << endl;
            arquivo << unidade.getQntUnidades() << endl;
        }
        arquivo.close();
        cout << "Unidades gravadas em formato de texto" << endl;
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

void Estoque::gravarTamanhos() {
    ofstream arquivo("tamanhos.txt", ios::app);
    if (arquivo.is_open()) {
        for (const auto& tamanho : tamanhos) {
            arquivo << tamanho.getMedidas() << endl;
            arquivo << tamanho.getQntTamanhos() << endl;
        }
        arquivo.close();
        cout << "Tamanhos gravados em formato de texto" << endl;
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

void Estoque::lerUnidades() {
    ifstream arquivo("unidades.txt");
    if (arquivo.is_open()) {
        string tipo;
        int qnt;
        while (getline(arquivo, tipo)) {
            arquivo >> qnt;
            arquivo.ignore();
            FardamentoUnidade unidade;
            unidade.setTipo(tipo);
            unidade.setQntUnidades(qnt);
            unidades.push_back(unidade);
        }
        arquivo.close();
        cout << "Unidades lidas em formato de texto" << endl;
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

void Estoque::lerTamanhos() {
    ifstream arquivo("tamanhos.txt");
    if (arquivo.is_open()) {
        string medida;
        int qnt;
        while (getline(arquivo, medida)) {
            arquivo >> qnt;
            arquivo.ignore();
            FardamentoTamanho tamanho;
            tamanho.setMedidas(medida);
            tamanho.setQntTamanhos(qnt);
            tamanhos.push_back(tamanho);
        }
        arquivo.close();
        cout << "Tamanhos lidos em formato de texto" << endl;
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

bool Estoque::adicionarUnidade(const FardamentoUnidade& unidade) {
    for (const auto& u : unidades) {
        if (u.getTipo() == unidade.getTipo()) {
            return false;
        }
    }
    unidades.push_back(unidade);
    return true;
}

bool Estoque::adicionarTamanho(const FardamentoTamanho& tamanho) {
    for (const auto& t : tamanhos) {
        if (t.getMedidas() == tamanho.getMedidas()) {
            return false;
        }
    }
    tamanhos.push_back(tamanho);
    return true;
}

bool Estoque::removerUnidade(const string& tipo) {
    for (auto it = unidades.begin(); it != unidades.end(); ++it) {
        if (it->getTipo() == tipo) {
            unidades.erase(it);
            return true;
        }
    }
    return false;
}

bool Estoque::removerTamanho(const string& medida) {
    for (auto it = tamanhos.begin(); it != tamanhos.end(); ++it) {
        if (it->getMedidas() == medida) {
            tamanhos.erase(it);
            return true;
        }
    }
    return false;
}

FardamentoUnidade Estoque::buscarUnidadePorTipo(const string& tipo) {
    for (const auto& unidade : unidades) {
        if (unidade.getTipo() == tipo) {
            return unidade;
        }
    }
    FardamentoUnidade unidade;
    unidade.setTipo("");
    unidade.setQntUnidades(0);
 // Retorna um objeto vazio se não encontrar
}

FardamentoTamanho Estoque::buscarTamanhoPorMedida(const string& medida) {
    for (const auto& tamanho : tamanhos) {
        if (tamanho.getMedidas() == medida) {
            return tamanho;
        }
    }
    FardamentoTamanho tamanhoVazio;
    tamanhoVazio.setMedidas("");
    tamanhoVazio.setQntTamanhos(0);
    return tamanhoVazio;
 // Retorna um objeto vazio se não encontrar
}

void Estoque::exibirTodasUnidades() {
    for (const auto& unidade : unidades) {
        cout << "Tipo: " << unidade.getTipo() << ", Quantidade: " << unidade.getQntUnidades() << endl;
    }
}

void Estoque::exibirTodosTamanhos() {
    for (const auto& tamanho : tamanhos) {
        cout << "Medida: " << tamanho.getMedidas() << ", Quantidade: " << tamanho.getQntTamanhos() << endl;
    }
}

void Estoque::setSenhaAcesso(const string& senha) {
    this->senhaAcesso = senha;
}

string Estoque::getSenhaAcesso() const {
    return senhaAcesso;
}

bool Estoque::verificarQuantidadeUnidade(int codigo, int quantidade) {
    for (auto &fardamentoUnidade : unidades) {
        if (fardamentoUnidade.getCodigo() == codigo && fardamentoUnidade.getQntUnidades() >= quantidade) {
            return true;
        }
    }
    return false;
}

bool Estoque::verificarQuantidadeTamanho(int codigo, int quantidade) {
    for (auto &fardamentoTamanho : tamanhos) {
        if (fardamentoTamanho.getCodigo() == codigo && fardamentoTamanho.getQntTamanhos() >= quantidade) {
            return true;
        }
    }
    return false;
}

void Estoque::venderFardamentoUnidade(const string& tipo, int quantidade) {
    for (auto& unidade : unidades) {
        if (unidade.getTipo() == tipo) {  // Assumindo que FardamentoUnidade tem um método getTipo() e métodos para ajustar quantidade.
            int novaQuantidade = unidade.getQntUnidades() - quantidade;
            if (novaQuantidade >= 0) {
                unidade.setQntUnidades(novaQuantidade);
            } else {
                cout << "Quantidade indisponível para venda." << endl;
            }
            return;
        }
    }
    cout << "Unidade do tipo " << tipo << " não encontrada." << endl;
}

void Estoque::venderFardamentoTamanho(const string& medida, int quantidade) {
    for (auto& tamanho : tamanhos) {
        if (tamanho.getMedidas() == medida) {  // Assumindo que FardamentoTamanho tem um método getMedida() e métodos para ajustar quantidade.
            int novaQuantidade = tamanho.getQntTamanhos() - quantidade;
            if (novaQuantidade >= 0) {
                tamanho.setQntTamanhos(novaQuantidade);
            } else {
                cout << "Quantidade indisponível para venda." << endl;
            }
            return;
        }
    }
    cout << "Tamanho com medida " << medida << " não encontrado." << endl;
}


void Estoque::ordenarUnidades() {
    sort(unidades.begin(), unidades.end(), [](const FardamentoUnidade &a, const FardamentoUnidade &b) -> bool {
        return a.getTipo() < b.getTipo();
    });
    cout << "Unidades ordenadas com sucesso!" << endl;
}

void Estoque::ordenarTamanhos() {
    sort(tamanhos.begin(), tamanhos.end(), [](const FardamentoTamanho &a, const FardamentoTamanho &b) -> bool {
        return a.getMedidas() < b.getMedidas();
    });
    cout << "Tamanhos ordenados com sucesso!" << endl;
}

void Estoque::reabastecerFardamentoUnidade(const string& tipo, int quantidade) {
    for (auto& unidade : unidades) {
        if (unidade.getTipo() == tipo) {
            int qntAtual = unidade.getQntUnidades();
            unidade.setQntUnidades(qntAtual + quantidade);
            cout << "Reabastecimento de unidade concluído!" << endl;
            break;
        }
    }
}

void Estoque::reabastecerFardamentoTamanho(const string& medida, int quantidade) {
    for (auto& tamanho : tamanhos) {
        if (tamanho.getMedidas() == medida) {
            int qntAtual = tamanho.getQntTamanhos();
            tamanho.setQntTamanhos(qntAtual + quantidade);
            cout << "Reabastecimento de tamanho concluído!" << endl;
            break;
        }
    }
}

Estoque::~Estoque() {
    gravarUnidades();
    gravarTamanhos();
}



