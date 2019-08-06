#include "Pilha.h"
#include <stdlib.h>


void inicializaPilha(struct tPilha* stack)
{
    stack->topo=NULL;   // inicializar a pilha din�mica � apenas setar o elemento do topo como nulo
}

struct tItemPilha* criaItem(char chave)   // criar item a ser inserido
{
    struct tItemPilha* it = (struct tItemPilha*) malloc(sizeof(struct tItemPilha));
    it->chave=chave;   // novo item da pilha com a chave estipulada
    it->anterior=NULL; // ponteiro que apontar� para o elemento de baixo
    return it;
}

struct tItemPilha* criaItemDouble(double chave)   // criar item a ser inserido
{
    struct tItemPilha* it = (struct tItemPilha*) malloc(sizeof(struct tItemPilha));
    it->chave = ' ';
    it->valor=chave;   // novo item da pilha com o valor
    it->anterior=NULL; // ponteiro que apontar� para o elemento de baixo
    return it;
}

struct tItemPilha* criaItemInt(int chave)   // criar item a ser inserido
{
    struct tItemPilha* it = (struct tItemPilha*) malloc(sizeof(struct tItemPilha));
    it->chave = ' ';
    it->disco=chave;   // novo item da pilha com o valor
    it->anterior=NULL; // ponteiro que apontar� para o elemento de baixo
    return it;
}

void push(struct tPilha* stack, struct tItemPilha* it)
{
    it->anterior=stack->topo;       // o antigo topo ser� o elemento anterior ao novo topo
    stack->topo=it;                 // o novo topo ser� o item inserido
}

struct tItemPilha* pop(struct tPilha* stack)
{
    struct tItemPilha *it = NULL;
    it=stack->topo;                                  // obtem elemento do topo
    if(stack->topo!=NULL) stack->topo=stack->topo->anterior;    // se a pilha n�o estiver vazia, o novo topo ser� o pr�ximo elemento (abaixo)
    return it;                                                  // retorna o antigo topo, removido
}

void imprimePilha(struct tPilha* stack) // imprime do topo para a base
{
    struct tItemPilha* i; printf("\n");
    for(i=stack->topo; i!=NULL; i=i->anterior) // percorre a partir do topo, seguindo para o elemento anterior, at� chegar na base
    {
        printf("%c\n", i->chave);
    }
}

int buscaPilha(struct tPilha* stack, char chave)
{

    struct tItemPilha* i; int j;
    for(i=stack->topo, j=0; i!=NULL; i=i->anterior, j++) // percorre a partir do topo, seguindo para o elemento anterior, at� chegar na base. Indice j � o indice do item atual
    {
        if(i->chave==chave) return j; // se item encontrado, retornar indice
    }
    return -1;                        // se n�o encontrar, retornar -1
}

