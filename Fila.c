#include "Fila.h"

struct tFila inicializaFila(int tam)
{
    struct tFila fila;
    fila.itens=(struct tItemFila*)malloc(tam*sizeof(struct tItemFila)); // aloca��o da fila no tamanho desejado
    fila.inicio=fila.fim=0;                                     // ponteiros inicio e fim na posi��o 0
    fila.tam=tam;                                               // tamanho de acordo com o tamanho alocado
    return fila;                                                // retorna a nova fila
}


// Funcao exclusiva para exercicio 5, enfileirar com prioridade
void enqueuePrioridade(struct tFila* queue, struct tItemFila it)
{
    int nfim=(queue->fim+1)%queue->tam;
    if(nfim!=queue->inicio)             // se a posi��o do novo final n�o for igual ao in�cio, quer dizer que ainda h� espa�o na fila
    {
        int i, j;
        // percorre a partir da posi��o inicio, at� chegar na posi��o fim ou elemento de menor prioridade
        for(i=queue->inicio; i!=queue->fim && queue->itens[i].prioridade <= it.prioridade; i=(i+1)%queue->tam);
        // inserir na posi��o encontrada, deslocando elementos
        for(j=nfim;j!=i; j=(j-1)%queue->tam)
        {
            queue->itens[j] = queue->itens[(j-1)%queue->tam];
        }
        queue->itens[i] = it;
        queue->fim=nfim;
    }
}

void enqueue(struct tFila* queue, struct tItemFila it)
{
    int nfim=(queue->fim+1)%queue->tam; // verifica a nova posi��o final da fila
    if(nfim!=queue->inicio)             // se a posi��o do novo final n�o for igual ao in�cio, quer dizer que ainda h� espa�o na fila
    {
        queue->itens[queue->fim]=it;    // insere item no final da fila
        queue->fim=nfim;                // fim agora aponta para a nova posi��o final
    }
}

struct tItemFila dequeue(struct tFila* queue)
{
    struct tItemFila it;
    if(queue->inicio!=queue->fim)                    // verifica se est� vazia
    {
        it=queue->itens[queue->inicio];              // acessa primeiro elemento da fila
        queue->inicio=(queue->inicio+1)%queue->tam;  // incrementa in�cio, que agora apontar� para a pr�xima posi��o
    }
    return it;                                       // retorna o item removido
}

void imprimeFila(struct tFila queue)
{
    int i;
    for(i=queue.inicio; i!=queue.fim ; i=(i+1)%queue.tam)   // percorre a partir da posi��o inicio, at� chegar na posi��o fim
                                                            // o incremento � feito considerando a circularidade, MOD tamanho
    {
        printf("%c[%d]", queue.itens[i].chave, queue.itens[i].prioridade);
    }
    printf("\n");
}

int buscaFila(struct tFila queue, char chave)
{
    int i;
    for(i=queue.inicio; i!=queue.fim ; i=(i+1)%queue.tam)   // percorre a partir da posi��o inicio, at� chegar na posi��o fim
                                                            // o incremento � feito considerando a circularidade, MOD tamanho
    {
        if(queue.itens[i].chave == chave) return i;         // se encontrar elemento, retornar o indice
    }
    return -1;                                              // caso contr�rio, retornar -1
}
