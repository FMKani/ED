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
        l->primeiro=l->ultimo=item;                     // O item inserido será o primeiro e último da lista.
    }
    else
    {
        while(atual!=NULL)        // Enquanto não encontrar onde inserir ou NULL
        {
            atual=atual->prox;
        }
        if(atual==NULL)                                 // Inserir no final
        {
            item->ant=l->ultimo;                        // O antigo último item será o antecessor do item inserido
            l->ultimo->prox=item;                       // O antigo último item terá como próximo o item inserido
            l->ultimo=item;                             // O item será o último da lista
        }
    }
}

void insereMeioLista(struct tLista* l, struct tItemLista* item, int pos)
{
    struct tItemLista* atual=l->primeiro;
    if(l->primeiro==NULL && l->ultimo==NULL)            // Inserir em lista vazia
    {
        l->primeiro=l->ultimo=item;                     // O item inserido será o primeiro e último da lista.
    }
    else
    {
        int indice = 0;
        while(atual!=NULL && indice < pos)                         // Enquanto não chegar na posição do item ou NULL
        {
            atual=atual->prox;
            indice += 1;                                           // Indice na próxima posição
        }
        if(atual!=NULL)                                        // Apenas entra se encontrou a posição para inserir e não é a ultima
        {
            item->ant=atual->ant;
            if(item->ant==NULL) l->primeiro=item;                   // Se estiver no início, o item será o primeiro da lista
            else atual->ant->prox=item;                             // Se não estiver no início, ele será o próximo de seu anterior
            atual->ant=item;
            item->prox=atual;
        }
        else                                                   // Senão, inserir no final
        {
            item->ant=l->ultimo;                               // O antigo último item será o antecessor do item inserido
            l->ultimo->prox=item;                              // O antigo último item terá como próximo o item inserido
            l->ultimo=item;                                    // O item será o último da lista
        }
    }

}

void removeLista(struct tLista* l, char n)
{
    struct tItemLista* atual=l->primeiro;
    if(l->primeiro!=NULL && l->ultimo!=NULL)                       // Remover apenas se a lista não estiver vazia.
    {
        while(atual!=NULL && atual->it!=n)                         // Enquanto não encontrar o item ou NULL
        {
            atual=atual->prox;
        }
        if(atual!=NULL)                                            // Apenas se encontrou o item a ser removido
        {
            if(atual->ant==NULL) l->primeiro=atual->prox;          // Se for o primeiro da lista, seu próximo se tornará o primeiro.
            else atual->ant->prox=atual->prox;
            if(atual->prox==NULL) l->ultimo=atual->ant;            // Se for o último da lista, seu anterior se tornará o último.
            else atual->prox->ant=atual->ant;
            free(atual);                                           // Desalocar item removido.
        }
    }
}

int buscaLista(struct tLista* lista, char x)
{
    int j; struct tItemLista* i;
    for(i=lista->primeiro, j=0; i!=NULL; i=i->prox, j++) // percorre lista, iniciando do primeiro item, e seguindo pelo ponteiro prox. Indice j é o indice do item atual
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

