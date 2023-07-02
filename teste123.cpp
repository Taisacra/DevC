#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void Sistema();
void assinatura();

typedef struct{

   	int codigo;
    char nome[20];
    int quantidade;
    float valor;

}Produto;


typedef struct Node {
    Produto dados;
    struct Node* next;
} Node;

Node* createNode(Produto dados) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dados = dados;
    newNode->next = NULL;
    return newNode;
}

//inserir no inicio
void insertAtBeginning(Node** head, Produto dados) {

    //usando a função createNode para criar um novo nó
    Node* newNode = createNode(dados);
    //como ele vai ser o novo nó ele deve pegar o enderço do antigo nó
    newNode->next = *head;
    //alterando o endereço da nova cabeça
    *head = newNode;
}

//inserir no fim
void insertAtEnd(Node** head, Produto dados) {

    Node* newNode = createNode(dados);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

//inserir no meio
void insertAfter(Node* prevNode, Produto dados) {
    if (prevNode == NULL) {
        printf("O nó anterior não pode ser nulo.\n");
        return;
    }

    Node* newNode = createNode(dados);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
//pecorrer lista
void displayList(Node* head) {
    Node* current = head;

    if (current == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos da lista: ");
    while (current != NULL) {
        printf("%d ", current->dados.codigo);
        printf("%s ", current->dados.nome);
        printf("%d ", current->dados.quantidade);
        printf("%f ", current->dados.valor);
        current = current->next;
    }
    printf("\n");
}

void removeNode(Node** head, int codigo) {

    //A Lista está vazia, então não há o que remover
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = *head;
    Node* prevNode = NULL;


    ///Se o dado estiver na cabeça da lista ele será removido
    if (current->dados.codigo == codigo) {
        *head = current->next;
        free(current);
        printf("Elemento removido: %d\n", codigo);
        return;
    }

    //Percorre a lista até encontrar o dado
    while (current != NULL && current->dados.codigo != codigo) {
        prevNode = current;
        current = current->next;
    }

    //Não Encontra

    if (current == NULL) {
        printf("Dado nao encontrado");
        return;
    }

    //remover o dado passado como parametro
    prevNode->next = current->next;
    free(current);
    printf("Elemento removido: %d\n", codigo);
}
//DEFININDO PILHA PARA PARTE DE VENDA
typedef struct{

   	int codigoProduto;
    int quantidadeProduto;
    float valorProduto;

}Venda;

typedef struct No {
    int data;
    struct Node* next;
} No;

//Definindo a Pilha
typedef struct Stack {
    Node* top;
} Stack;

//Criando uma Pilha
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

//Verifica se a pilha está vazia se re
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

//Empilhar
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}


//Desmpilhar
int pop(Stack* stack) {

    if (isEmpty(stack)) {
        printf("A pilha está vazia!\n");
        return -1;
    }

    Nodede* temp = stack->top;
    // o dado que ele retirou da pilha
    int data = temp->data;
    //Proximo vai ser o topo
    stack->top = temp->next;
    //limpar
    free(temp);
    //retornando o dado que eu desempilhei
    return data;
}




int main(){
	assinatura();
   Node* head = NULL;
    int op;
    Produto produto;

    do{

        Sistema();
        scanf("%d", &op);

        switch(op){

            case 1:
                printf("Digite o codigo do produto: \n");
                scanf("%d", &produto.codigo);
                printf("Digite o nome do produto: \n");
                scanf("%s", produto.nome);
                printf("Digite a quantidade do produto: \n");
                scanf("%d", &produto.quantidade);
                printf("Digite o valor do produto: \n");
                scanf("%f", &produto.valor);

                insertAtEnd(&head, produto);
                break;

            case 2:
                printf("Informe o codigo do produto a ser removido:\n ");
                scanf("%d", &produto.codigo);
                printf("Informe a quantidade a ser removido: ");
                scanf("%d", &produto.quantidade);

                //removeNode(&head, produto.codigo);
                break;

            case 3:
                printf("Informe o codigo do produto para atualizar \n");
                scanf("%d", &produto.codigo);
                printf("Informe a nova quantidade: ");
                scanf("%d", &produto.quantidade);

                //atualizarQuantidade(head, produto.codigo, produto.quantidade);
                break;

            case 4:
                printf(" Exibir estoque atualizado\n");
                displayList(head);
                break;

            case 5:
                printf("5. Exibir vendas\n");
                break;

            case 6:
                printf("6. Total vendido\n");
                break;

            case 7:
                printf("7. Sair\n");
                break;

             case 8:
                printf("Saindo do Sitema...\n");
                break;

            default:
                printf("Opcao invalida!");
                break;

            }

        }while(op!=8);
}


void Sistema(){

    printf("\n=========SISTEMA DE GERENCIAMENTO E VENDA DO MERCADO=======\n");
    printf("1. Adicionar produto ao estoque\n");
    printf("2. Remover produto do estoque\n");
    printf("3. Atualizar quantidade de produto no estoque\n");
    printf("4. Exibir estoque atualizado\n");
    printf("5. Registrar venda\n");
    printf("6. Exibir vendas\n");
    printf("7. Total vendido\n");
    printf("8. Sair\n");
    printf("Escolha um opcao:");
}

void assinatura(){
	printf("Fazer assinatura!");
}
 
