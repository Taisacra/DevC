#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

//Strutura da lista
typedef struct{
   	int codigo;
    char nome[20];
    int quantidade;
    float valor;
}Produto;

int cont = 0;

typedef struct Node{
	//Variavel dados do tipo Produto, dados é um ponteiro para estrutura produto
    Produto dados;
    //Estrutura de ponteiro para o proximo Nó
    struct Node* next;
} Node;

//Criar um novo nó na lista recebe como parâmetro os dados do produto que será armazenado no novo nó
Node* criarProduto(Produto dados) {
    Node* novoProduto = (Node*)malloc(sizeof(Node));
    // (-> usado para acessar membros de uma estrutura atraves de um ponteiro para essa estrutura) atribuir os dados do produto ao novo nó
    novoProduto->dados = dados;
    novoProduto->next = NULL;
    return novoProduto;
}

//inserir no fim
void adcProduto(Node** estoque, Produto dados) {
    Node* novoProduto = criarProduto(dados);

    if (*estoque == NULL) {
        *estoque = novoProduto;
        return;
    }

    Node* produtoAtual = *estoque;
    while (produtoAtual->next != NULL) {
        produtoAtual = produtoAtual->next;
    }
    produtoAtual->next = novoProduto;// o fim aponta para o novo ultimo elemento inserido
}

void cadastrarProduto(Node**estoque){
     Produto dados;
     printf("---------------------------------------\n");
     printf("          Cadastro de Produto          \n");
     printf("---------------------------------------\n");
     printf("Codigo do produto: ");
     scanf("%d", &dados.codigo);
     printf("Nome do produto: ");
     scanf("%s", &dados.nome);
     printf("Quantidade do produto: ");
     scanf("%d", &dados.quantidade);
     printf("Valor do produto: ");
     scanf("%f", &dados.valor);

    adcProduto(estoque , dados);
    printf("---------------------------------------\n");
    printf("----Produto cadastrado com sucesso!----\n");
    printf("---------------------------------------\n");


}

//pecorrer estoque e imprime os itens contido no estoque
void exibirEstoque(Node* estoque) {
    Node*  produtoAtual = estoque;

    if ( produtoAtual == NULL) {
        printf("O estoque está vazia.\n");
        return;
    }

    printf("Elementos do estoque: ");
    while ( produtoAtual != NULL) {
        printf("\n======= Listando produtos-ESTOQUE =======\n");
        printf("\n%d \n%s \n%d \n%f ",  produtoAtual->dados.codigo,  produtoAtual->dados.nome,  produtoAtual->dados.quantidade,  produtoAtual->dados.valor);
         produtoAtual =  produtoAtual->next;
    }
    printf("\n");
}


void removerProduto(Node** estoque) {
    if (*estoque == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    int remover;
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%d", &remover);

    Node* produtoAtual = *estoque;
    Node* rodutoAnterior = NULL;

    if (produtoAtual->dados.codigo == remover) {
        *estoque = produtoAtual->next;
        free(produtoAtual);
        printf("Elemento removido do estoque! \n");
        return;
    }

    while (produtoAtual != NULL && produtoAtual->dados.codigo != remover) {
        rodutoAnterior  = produtoAtual;
        produtoAtual = produtoAtual->next;
    }

    if (produtoAtual == NULL) {
        printf("O elemento %d não está presente na lista.\n", remover);
        return;
    }

    rodutoAnterior ->next = produtoAtual->next;
    free(produtoAtual);
    printf("Elemento removido com sucesso\n");
}


Node* procurarProduto(Node* estoque){
	Node*  produtoAtual = estoque;
        int cod;
        printf("\n======= Procurar produto =======\n");
        printf("Informe o codigo do produto: ");
        scanf("%d",&cod);

	while( produtoAtual!=NULL){
		if( produtoAtual->dados.codigo ==cod){
			return  produtoAtual;
		}
		 produtoAtual=  produtoAtual->next;
	}
	return NULL;
}

//DEFININDO PILHA PARA PARTE DE VENDA
//Strutura da Pilha venda

typedef struct Venda {
    int cod;
    int qtd;
    char nome[25];
    float valor;
} Venda;

typedef struct NoPilha {
    Venda data;
    struct NoPilha* next;
} NoPilha;

typedef struct PilhaVenda{
    NoPilha* topo;
}PilhaVenda;

PilhaVenda* criarPilhaVenda() {
    PilhaVenda*pilhaVenda = (PilhaVenda*)malloc(sizeof(PilhaVenda));
    pilhaVenda->topo = NULL;
    return pilhaVenda;
}

int estaVazia(PilhaVenda* pilhaVenda) {
    return (pilhaVenda->topo == NULL);
}

void empilhar (PilhaVenda* pilhaVenda, Venda* data) {
    NoPilha* newNo = (NoPilha*)malloc(sizeof(NoPilha));
    newNo->data = *data;
    newNo->next = pilhaVenda->topo;
    pilhaVenda->topo = newNo;
}

Venda desempilhar(PilhaVenda* pilhaVenda) {

    if (estaVazia(pilhaVenda)) {
        printf("A pilha esta vazia.\n");
        Venda venda_vazia = { 0, 0, 0.0 };
        return venda_vazia;
    }

    NoPilha* temp = pilhaVenda->topo;
    Venda data = temp->data;
    pilhaVenda->topo = temp->next;
    free(temp);
    return data;
}

void VenderProduto(Node** estoque, PilhaVenda* pilhaVenda) {
    Venda venda;

    if (*estoque == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int cod, qtd;
    float valor = 0.0;

    printf("Informe o codigo do produto que sera vendido: ");
    scanf("%d", &cod);
    printf("Informe a quantidade desejada: ");
    scanf("%d", &qtd);

    Node* produtoAtual = *estoque;

    while (produtoAtual != NULL) {
        if (produtoAtual->dados.codigo == cod) {
            if (produtoAtual->dados.quantidade >= qtd) {
                valor = produtoAtual->dados.valor * qtd;
                produtoAtual->dados.quantidade -= qtd;
                printf("\nTotal da venda: R$%.2f\n", valor);
                printf("Sobraram %d no estoque.\n", produtoAtual->dados.quantidade);

                venda.cod = cod;
                venda.qtd = qtd;
                venda.valor = valor;
                empilhar(pilhaVenda, &venda);
            } else {
                printf("Quantidade insuficiente no estoque.\n");
            }
            break;
        }
        produtoAtual = produtoAtual->next;
    }

    if (produtoAtual == NULL) {
        printf("Produto nao encontrado.\n");
        return;
    }
}

// Função para cancelar a venda mais recente
int cancelarVenda(PilhaVenda* pilhaVenda, Node* estoque) {
    if (estaVazia(pilhaVenda)) {

    }

    Venda venda = desempilhar(pilhaVenda);

    Node* produtoAtual = estoque;
    while (produtoAtual != NULL) {
        if (produtoAtual->dados.codigo == venda.cod) {
            produtoAtual->dados.quantidade = produtoAtual->dados.quantidade + venda.qtd;

            printf("Venda cancelada.\n");
            return 1;
        }
        produtoAtual = produtoAtual->next;
    }

    printf("Produto da venda nao encontrado no estoque.\n");
}


void menuPrincipal();
void GerenciamentoEstoque();
void venda();
void assinatura();
void SistemaVenda();

int main() {

    Node* estoque = NULL; 
    Node* produtoAtual= NULL;
    Venda venda;
    PilhaVenda* pilhaVenda = criarPilhaVenda();
    int op, opGerenciamento, opVenda;
    Produto dados;

    do {
        assinatura();
        menuPrincipal();
        scanf("%d", &op);
        system("cls");

        switch (op) {
            assinatura();
            case 1:
                do {
                    assinatura();
                    GerenciamentoEstoque();
                    scanf("%d", &opGerenciamento);
                    system("cls");
                    switch (opGerenciamento) {

                        case 1:
                            cadastrarProduto(estoque);
                            Sleep('15');
                            system("cls");
                            break;
                        case 2:
                           procurarProduto(estoque);
                            Sleep('15');
                            break;
                        case 3:
                            exibirEstoque(estoque);
                            Sleep('15');
                            system("cls");
                            break;
                        case 4:
                            removerProduto(estoque);
                            Sleep('15');
                            system("cls");
                            break;

                        case 5:
                            printf("Saindo... \nRetornando para o Menu principal.\n");
                            system("cls");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            system("cls");
                            break;
                    }
                } while (opGerenciamento != 5); // Condição de saída do loop interno
                break;

            case 2:
                do {
                    assinatura();
                    SistemaVenda();
                    scanf("%d", &opVenda);
                    system("cls");

                    switch (opVenda) {
                        case 1:
                            VenderProduto(&estoque, pilhaVenda);
                            printf("=============Registrar venda==============\n");
                            printf("-------------------------------------\n");
                            printf("----Venda realizada com sucesso!----\n");
                            printf("-------------------------------------\n");
                            break;

                        case 2:
                            printf("=========Exibir vendas realizadas==========\n");
                            while (!estaVazia(pilhaVenda)) {
                                venda = desempilhar(pilhaVenda);
                                printf("Codigo: %d\n", venda.cod);
                                printf("Quantidade: %d\n", venda.qtd);
                                printf("Valor: %.2f\n", venda.valor);
                            }
                            break;

                        case 3:
                           /*if (!cancelarVenda(stack,head)) {
                                printf("Nenhuma venda cancelada.\n");
                            }
                            printf("-------------------------------------\n");
                            printf("----Venda cancelada com sucesso!----\n");
                            printf("-------------------------------------\n");*/
                            break;

                        case 4:
                            printf("Saindo do Sistema...\n");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (opVenda != 4);
                break;

            case 3:
                printf("Retornando para o Menu principal.\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (op != 3);
    return 0;
}

void menuPrincipal(){
    printf("======================MENU PRINCIPAL==========================\n");
    printf("1. GERENCIAMENTO- ESTOQUE\n");
    printf("2. VENDA\n");
    printf("3. SAIR DO SISTEMA.\n");
    printf("Escolha um opcao:");
    printf("\n\n");
}

void GerenciamentoEstoque(){

    printf("\n=========SISTEMA DE GERENCIAMENTO E ESTOQUE=======\n");
    printf("1. Adicionar produto ao estoque\n");
    printf("2. Procurar produto\n");
    printf("3. Exibir estoque\n");
    printf("4. Remover produto do estoque\n");
    printf("5. Sair\n");
    printf("Escolha um opcao:");
    printf("\n\n");
}

void SistemaVenda(){
     printf("\n=========SISTEMA DE VENDA=======\n");
    printf("1. Registrar venda\n");
    printf("2. Exibir vendas\n");
    printf("3. Total vendido\n");
    printf("4. Sair\n");
    printf("Escolha um opcao:");
    printf("\n\n");
}

void assinatura(){

    printf("              .                          .                \n");
    printf("               .0000000000    0000000001,                 \n");
    printf("               0000,,,+0000000000+,,.0000                 \n");
    printf("              +000,,,,,,,000000,,,,,,,0000                \n");
    printf("               0001,,,,++,0000+,,,,,,1000                 \n");
    printf("    ,    .00000+000000110000000010000000010000.    .      \n");
    printf("      ,000000000000000000000000000000000000000000,        \n");
    printf("      000,+,,,+000000001,,,,,,,,100000001,,+,,,000        \n");
    printf("       000,,,,,,00000,,,,,,,,,,,,+,00000,,,++,000         \n");
    printf("        .00000000000,,,,,,,,,,,,,,++00000000000.          \n");
    printf("         . 00000000+,,,,,,,,,,,,,,,,+00000000             \n");
    printf("             .000000,,,,,010000,,,,+000000.               \n");
    printf("               ,000000000000000000000000+                 \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000                  \n");
    printf("                000000000000000000000000,                 \n");
    printf("               +0000000000000000000000001                 \n");
    printf("               00000000000000000000000000                 \n");
    printf("               00000000000000000000000000                 \n");
    printf("               00000000000000000000000000                 \n");
    printf("              .00000000000000000000000000.                \n");
    printf("              1000000000000000000000000000                \n");
    printf("              0000000000000000000000000000                \n");

    printf("===================SISTEMA MERCADO==========================\n");
	printf("\n\n");
}

