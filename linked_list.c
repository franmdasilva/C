#include <stdio.h> 
#include <stdlib.h> 

// vamos criar um nó de uma linked list
    typedef struct no { /*o nó possui um atributo, neste caso valor,
    e um pointer que aponta para o próximo nó, de forma que esta struct é recursiva */
    int valor;
    struct no* proximo;
    } no_t;

    // vamos criar uma função para imprimir os itens da linked list
    
    void print_linked(no_t * cab) {
    no_t* atual = cab;

    while (atual != NULL) {
        printf("\n %d", atual->valor);
        atual = atual->proximo;
    }
    }

    void pushf(no_t* cab, int val) { // esta funcao vai até o final da lista e adiciona mais um nó
    no_t* atual = cab;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = (no_t*) malloc(sizeof(no_t));
    atual->proximo->valor = val;
    atual->proximo->proximo = NULL;

    }

    void pushi(no_t** cab, int val) { // esta função adiciona um nó no começo da lista

    no_t* novo_no = (no_t*) malloc(sizeof(no_t));

    novo_no->valor = val;
    novo_no->proximo = *cab;
    *cab = novo_no;
    }

    void popi(no_t** cab) { // esta função retira um nó no começo da lista
        no_t* novo_no= NULL;

        if (*cab == NULL) {
            return;
        } 

        novo_no= (*cab)->proximo;
        free(*cab);
        *cab= novo_no;
    }

    void popf(no_t* cab) { // esta função retira um nó no final da lista
        if (cab->proximo == NULL){
            free(cab);
        }

        no_t* atual= cab;
        while (atual->proximo->proximo != NULL){
            atual= atual->proximo;
        }
        
        free(atual->proximo);
        atual->proximo= NULL;
    }

    void pop_by_index(no_t** cab, int n){ // esta função retira um nó da lista pelo seu indice
        int i=0;
        no_t* atual= *cab;
        no_t* no_n= NULL;

        if (n==0){
            return popi(cab);
        }

        for(i=0; i< n-1; i++){
            if(atual->proximo == NULL){
                return;
            }

            atual= atual->proximo;
        }

        no_n= atual->proximo;
        atual->proximo= no_n->proximo;
        free(no_n);
    }

    void pop_by_value(no_t **head, int val) { // esta função retira um nó da lista pelo seu valor
    no_t *previous, *current;

    if (*head == NULL) {
        return;
    }

    if ((*head)->valor == val) {
        return popi(head);
    }

    previous = current = (*head)->proximo;
    while (current) {
        if (current->valor == val) {
            previous->proximo = current->proximo;
            free(current);
            return;
        }

        previous = current;
        current  = current->proximo;
    }
    }

int main() {

    // vamos criar uma variável local que aponta o inicio da linked list
    no_t* cabeca= NULL;

    // agora vamos alocar espaço para a variavel
    cabeca= (no_t*) malloc(sizeof(no_t));

    if (cabeca== NULL){
    return;
    }

    // vamos popular a linked list
    cabeca->valor= 1;
    cabeca->proximo= (no_t*) malloc(sizeof(no_t));
    cabeca->proximo->valor= 2;
    cabeca->proximo->proximo= NULL;
     
    pushf(cabeca,3);
    pushf(cabeca,4);
    pushf(cabeca,5);
    pushi(&cabeca,0); 
    pushi(&cabeca,-1);
    pushi(&cabeca,-2);

    // imprimindo nossa lista
    printf("\n linked list");
    print_linked(cabeca);

    popi(&cabeca);
    printf("\n linked list depois de retirar primeiro item");
    print_linked(cabeca);

    popf(cabeca);
    printf("\n linked list depois de retirar último item");
    print_linked(cabeca);

    pop_by_index(&cabeca,3);
    printf("\n linked list depois de retirar terceiro item");
    print_linked(cabeca);

    pop_by_value(&cabeca,3);
    printf("\n linked list depois de retirar item com valor igual a 3");
    print_linked(cabeca);

    return 0;
}