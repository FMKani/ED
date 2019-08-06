struct tItemFila
{
    char chave;
    int prioridade; // utilizado exclusivamente para o exercicio 5
};

struct tFila
{
    struct tItemFila *itens;
    int inicio, fim, tam;
};

struct tFila inicializaFila(int);
void enqueue(struct tFila*, struct tItemFila it);
struct tItemFila dequeue(struct tFila*);
int buscaFila(struct tFila,char);
void imprimeFila(struct tFila);
