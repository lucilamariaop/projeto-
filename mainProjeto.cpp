#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;

#include "Fardamento.cpp"
#include "FardamentoUnidade.cpp"
#include "FardamentoTamanho.cpp"
#include "Estoque.cpp"
#include "Carrinho.cpp"



int Menu_Cliente() {
    int opcao;
    cout << ".................................." << endl;
    cout << "...........  Cliente  ............" << endl;
    cout << "Listar Produtos..................1" << endl;
    cout << "Adicionar Produto ao carrinho....2" << endl;
    cout << "Remover Produto do carrinho.....3" << endl;
    cout << "Finalizar compra.................4" << endl;
    cout << "Sair.............................0" << endl;
    cout << ".................................." << endl;
    cout << "Opção: ";
    cin >> opcao;
    return opcao;
}

int Menu_Gerente() {
    int opcao;
    cout << ".................................." << endl;
    cout << ".......... Funcionário ..........." << endl;
    cout << "Cadastrar Produtos...............1" << endl;
    cout << "Listar Produtos..................2" << endl;
    cout << "Adicionar Produto.................3" << endl;
    cout << "Remover Produto..................4" << endl;
    cout << "Sair.............................0" << endl;
    cout << ".................................." << endl;
    cout << "Opção: ";
    cin >> opcao;
    return opcao;
}

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    Estoque estoque;
    Carrinho carrinho;
    FardamentoUnidade fardamentoUnidade;
    FardamentoTamanho fardamentoTamanho;
    string tipo;
    string medida;
    int qntUnidades;
    int codigo;
    int opcao;
    float preco; 
    string nome;
    bool loop = true;

    while (loop) {
        cout << "........ LOJA DE FARDAMENTOS ........." << endl;
        cout << "..Escolha uma das opções abaixo...\n";
        cout << "Cliente...........................1\n";
        cout << "Gerente...........................2\n";
        cout << "Sair..............................0\n";
        cout << "..................................." << endl;
        cout << "\nOpção: ";
        cin >> opcao;
        system("cls");

        switch (opcao) {
            case 1: {
                int cliente_opcao;
                do {
                    cliente_opcao = Menu_Cliente();
                    switch (cliente_opcao) {
                        case 1:
                            cout << "Listando Produtos..." << endl;
                             estoque.exibirTodasUnidades();
                			 estoque.exibirTodosTamanhos();
                		break;
							
                        
                        case 2:
                            cout << "Adicionar Produto ao carrinho..." << endl;
                            
                        cout << "Informe o tipo do fardamento que deseja adicionar ao carrinho (Unidade/Tamanho): ";
                cin >> tipo;

                if (tipo == "Unidade") {
                    cout << "Informe o tipo de unidade (por exemplo, 'camisa', 'calça', etc.): ";
                    string tipoUnidade;
                    cin >> tipoUnidade;

                    FardamentoUnidade fardamento = estoque.buscarUnidadePorTipo(tipoUnidade);
                    if (!fardamento.getNome().empty()) {
                        carrinho.add_unidade(fardamentoUnidade);
                        cout << "Fardamento adicionado ao carrinho." << endl;
                    } else {
                        cout << "Fardamento não encontrado." << endl;
                    }
                } else if (tipo == "Tamanho") {
                    cout << "Informe a medida do fardamento (P/M/G): ";
                    string medida;
                    cin >> medida;

                    FardamentoTamanho fardamento = estoque.buscarTamanhoPorMedida(medida);
                    if (!fardamento.getNome().empty()) {
                        carrinho.add_tamanho(fardamentoTamanho);
                        cout << "Fardamento adicionado ao carrinho." << endl;
                    } else {
                        cout << "Fardamento não encontrado." << endl;
                    }
                } else {
                    cout << "Tipo inválido!" << endl;
                }
                break;
                            
                        case 3:
                            cout << "Remover Produto do carrinho..." << endl;
                             {
				string tipoDeFardamento;
                cout << "Informe o tipo do fardamento que deseja remover (Unidade/Tamanho): ";
                cin >> tipoDeFardamento;

                if (tipoDeFardamento == "Unidade") {
                    carrinho.remove_unidade(codigo);
                } else if (tipoDeFardamento == "Tamanho") {
                    carrinho.remove_tamanho(codigo);
                } else {
                    cout << "Tipo de fardamento inválido." << endl;
                }
                break;
				}
                
                        case 4:
                            cout << "Finalizar compra..." << endl;
                            carrinho.finalizarCompra();
                break;
                            break;
                        case 0:
                            cout << "Saindo do modo cliente..." << endl;
                            break;
                        default:
                            cout << "Opção inválida! Tente novamente." << endl;
                            break;
                    }
                } while (cliente_opcao != 0);
                break;
            }
            case 2: {
                int gerente_opcao;
                do {
                    gerente_opcao = Menu_Gerente();
                    switch (gerente_opcao) {
                        case 1:
                            cout << "Cadastrando Produtos..." << endl;
                            cout << "Informe o nome do fardamento: ";
                cin >> nome;
                cout << "Informe o tipo (Unidade/Tamanho): ";
                cin >> tipo;
                cout << "Informe o preço: ";
                cin >> preco;
                if (tipo == "Unidade") {
                    cout << "Informe a quantidade de unidades: ";
                    cin >> qntUnidades;
                    fardamentoUnidade.setNome(nome);
                    fardamentoUnidade.setPreco(preco);
                    fardamentoUnidade.setQntUnidades(qntUnidades);
                    estoque.adicionarUnidade(fardamentoUnidade);
                } else if (tipo == "Tamanho") {
                    cout << "Informe a medida (P/M/G): ";
                    cin >> medida;
                    fardamentoTamanho.setNome(nome);
                    fardamentoTamanho.setPreco(preco);
                    fardamentoTamanho.setMedidas(medida);
                    estoque.adicionarTamanho(fardamentoTamanho);
                }
                break;
                           
                        case 2:
                            cout << "Listando Produtos..." << endl;
                           estoque.exibirTodasUnidades();
               				 estoque.exibirTodosTamanhos();
               			 break;

                            break;
                        case 3:
                            cout << "Remover Produto..." << endl;
                           {
				cout << "Deseja remover um fardamento por Tipo ou por Medida? (Digite 'Tipo' ou 'Medida'): ";
                string escolha;
                cin >> escolha;

                if (escolha == "Tipo") {
					cout << "Informe o tipo do fardamento que deseja remover: ";
                    string tipo;
                    cin >> tipo;
                    if (estoque.removerUnidade(tipo)) {
                        cout << "Fardamento removido com sucesso!" << endl;
                    } else {
                        cout << "Erro ao remover fardamento." << endl;
                    }
                } else if (escolha == "Medida") {
                    cout << "Informe a medida do fardamento que deseja remover: ";
                    string medida;
                    cin >> medida;
                    if (estoque.removerTamanho(medida)) {
                        cout << "Fardamento removido com sucesso!" << endl;
                    } else {
                        cout << "Erro ao remover fardamento." << endl;
                    }
                } else {
                    cout << "Escolha inválida." << endl;
                }
                break;}
                        case 0:
                            cout << "Saindo do modo gerente..." << endl;
                            break;
                        default:
                            cout << "Opção inválida! Tente novamente." << endl;
                            break;
                    }
                } while (gerente_opcao != 0);
                break;
            }
            case 0:
                cout << "Encerrando o programa..." << endl;
                loop = false;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    }

    return 0;
}






