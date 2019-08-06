#include "Fila.h"

struct tFila inicializaFila(int tam)
{
    struct tFila fila;
    fila.itens=(struct tItemFila*)malloc(tam*sizeof(struct tItemFila)); // alocação da fila no tamanho desejado
    fila.inicio=fila.fim=0;                                     // ponteiros inicio e fim na posição 0
    fila.tam=tam;                                               // tamanho de acordo com o tamanho alocado
    return fila;                                                // retorna a nova fila
}


// Funcao exclusiva para exercicio 5, enfileirar com prioridade
void enqueuePrioridade(struct tFila* queue, struct tItemFila it)
{
    int nfim=(queue->fim+1)%queue->tam;
    if(nfim!=queue->inicio)             // se a posição do novo final não for igual ao início, quer dizer que ainda há espaço na fila
    {
        int i, j;
        // percorre a partir da posição inicio, até chegar na posição fim ou elemento de menor prioridade
        for(i=queue->inicio; i!=queue->fim && queue->itens[i].prioridade <= it.prioridade; i=(i+1)%queue->tam);
        // inserir na posição encontrada, deslocando elementos
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
    int nfim=(queue->fim+1)%queue->tam; // verifica a nova posição final da fila
    if(nfim!=queue->inicio)             // se a posição do novo final não for igual ao início, quer dizer que ainda há espaço na fila
    {
        queue->itens[queue->fim]=it;    // insere item no final da fila
        queue->fim=nfim;                // fim agora aponta para a nova posição final
    }
}

struct tItemFila dequeue(struct tFila* queue)
{
    struct tItemFila it;
    if(queue->inicio!=queue->fim)                    // verifica se está vazia
    {
        it=queue->itens[queue->inicio];              // acessa primeiro elemento da fila
        queue->inicio=(queue->inicio+1)%queue->tam;  // incrementa início, que agora apontará para a próxima posição
    }
    return it;                                       // retorna o item removido
}

void imprimeFila(struct tFila queue)
{
    int i;
    for(i=queue.inicio; i!=queue.fim ; i=(i+1)%queue.tam)   // percorre a partir da posição inicio, até chegar na posição fim
                                                            // o incremento é feito considerando a circularidade, MOD tamanho
    {
        printf("%c[%d]", queue.itens[i].chave, queue.itens[i].prioridade);
    }
    printf("\n");
}

int buscaFila(struct tFila queue, char chave)
{
    int i;
    for(i=queue.inicio; i!=queue.fim ; i=(i+1)%queue.tam)   // percorre a partir da posição inicio, até chegar na posição fim
                                                            // o incremento é feito considerando a circularidade, MOD tamanho
    {
        if(queue.itens[i].chave == chave) return i;         // se encontrar elemento, retornar o indice
    }
    return -1;                                              // caso contrário, retornar -1
}
