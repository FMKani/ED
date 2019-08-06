#include "Lista.h"
#include <stdlib.h>

    /*int n, nn;
    char ch;
    struct tLista lista;
    novaLista(&lista);
    while(ch=getchar())
    {
        if(ch=='I'){scanf("\n%d", &n); insereFinalLista(&lista, criaItemLista(n));}
        if(ch=='O'){scanf("\n%d %d", &n, &nn); insereMeioLista(&lista, criaItemLista(n), nn);}
        if(ch=='R'){scanf("\n%d", &n); removeLista(&lista, n);}
        if(ch=='B'){scanf("\n%d", &n); printf("%d\n", buscaLista(&lista, n));}
        if(ch=='M') imprimeLista(&lista);
        //if(ch=='F') mostraListaF(&lista);
        //if(ch=='D') desalocaLista(&lista);
    }*/

void novaLista(struct tLista* l)
{
    l->primeiro=NULL;
    l->ultimo=NULL;
}
struct tItemLista* criaItemLista(char x)						   // cria novo itiem para ser inserido na lista
{
    struct tItemLista* item;
    item=(struct tItemLista*)malloc(sizeof(struct tItemLista));
    item->it=x;                                       // chave do novo item
    item->prox=NULL;								  // ponteiro proximo elemento
    item->ant=NULL;									  // ponteiro elemento anterior
    return item;
}

void insereFinalLista(struct tLista* l, struct tItemLista* item)
{
    struct tItemLista* atual=l->primeiro;
    if(l->primeiro==NULL && l->ultimo==NULL)            // Inserir em lista vazia
    {
        l->primeiro=l->ultimo=item;                     // O item inserido ser� o primeiro e �ltimo da lista.
    }
    else
    {
        while(atual!=NULL)        // Enquanto n�o encontrar onde inserir ou NULL
        {
            atual=atual->prox;
        }
        if(atual==NULL)                                 // Inserir no final
        {
            item->ant=l->ultimo;                        // O antigo �ltimo item ser� o antecessor do item inserido
            l->ultimo->prox=item;                       // O antigo �ltimo item ter� como pr�ximo o item inserido
            l->ultimo=item;                             // O item ser� o �ltimo da lista
        }
    }
}

void insereMeioLista(struct tLista* l, struct tItemLista* item, int pos)
{
    struct tItemLista* atual=l->primeiro;
    if(l->primeiro==NULL && l->ultimo==NULL)            // Inserir em lista vazia
    {
        l->primeiro=l->ultimo=item;                     // O item inserido ser� o primeiro e �ltimo da lista.
    }
    else
    {
        int indice = 0;
        while(atual!=NULL && indice < pos)                         // Enquanto n�o chegar na posi��o do item ou NULL
        {
            atual=atual->prox;
            indice += 1;                                           // Indice na pr�xima posi��o
        }
        if(atual!=NULL)                                        // Apenas entra se encontrou a posi��o para inserir e n�o � a ultima
        {
            item->ant=atual->ant;
            if(item->ant==NULL) l->primeiro=item;                   // Se estiver no in�cio, o item ser� o primeiro da lista
            else atual->ant->prox=item;                             // Se n�o estiver no in�cio, ele ser� o pr�ximo de seu anterior
            atual->ant=item;
            item->prox=atual;
        }
        else                                                   // Sen�o, inserir no final
        {
            item->ant=l->ultimo;                               // O antigo �ltimo item ser� o antecessor do item inserido
            l->ultimo->prox=item;                              // O antigo �ltimo item ter� como pr�ximo o item inserido
            l->ultimo=item;                                    // O item ser� o �ltimo da lista
        }
    }

}

void removeLista(struct tLista* l, char n)
{
    struct tItemLista* atual=l->primeiro;
    if(l->primeiro!=NULL && l->ultimo!=NULL)                       // Remover apenas se a lista n�o estiver vazia.
    {
        while(atual!=NULL && atual->it!=n)                         // Enquanto n�o encontrar o item ou NULL
        {
            atual=atual->prox;
        }
        if(atual!=NULL)                                            // Apenas se encontrou o item a ser removido
        {
            if(atual->ant==NULL) l->primeiro=atual->prox;          // Se for o primeiro da lista, seu pr�ximo se tornar� o primeiro.
            else atual->ant->prox=atual->prox;
            if(atual->prox==NULL) l->ultimo=atual->ant;            // Se for o �ltimo da lista, seu anterior se tornar� o �ltimo.
            else atual->prox->ant=atual->ant;
            free(atual);                                           // Desalocar item removido.
        }
    }
}

int buscaLista(struct tLista* lista, char x)
{
    int j; struct tItemLista* i;
    for(i=lista->primeiro, j=0; i!=NULL; i=i->prox, j++) // percorre lista, iniciando do primeiro item, e seguindo pelo ponteiro prox. Indice j � o indice do item atual
    {
        if(i->it==x) return j; 							 // se item encontrado, retornar indice
    }
    return -1;
}

void imprimeLista(struct tLista* lista)
{
    struct tItemLista* i;
    for(i=lista->primeiro; i!=NULL; i=i->prox)  // percorre lista, iniciando do primeiro item, e seguindo pelo ponteiro prox
    {
        printf("%c ", i->it);					// imprime chave do item atual
    }
    printf("\n");
}

