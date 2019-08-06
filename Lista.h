struct tItemLista
{
    char it;
    struct tItemLista* prox;
    struct tItemLista* ant;
};

struct tLista
{
    struct tItemLista* primeiro;
    struct tItemLista* ultimo;
};

void novaLista(struct tLista*);
struct tItemLista* criaItemLista(char);
void insereMeioLista(struct tLista*, struct tItemLista*, int pos);
void insereFinalLista(struct tLista*, struct tItemLista*);
void removeLista(struct tLista*, char);
int buscaLista(struct tLista*, char);
void imprimeLista(struct tLista*);
