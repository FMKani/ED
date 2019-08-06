struct tItemPilha
{
    char chave;
    double valor; // campo double utilizado apenas para a questao 2
    int disco;    // campo int utilizado apenas para questao 6
    struct tItemPilha *anterior;
};

struct tPilha
{
    struct tItemPilha *topo;
    char nome;
};

struct tItemPilha* criaItem(char chave);
struct tItemPilha* criaItemInt(int valor);
struct tItemPilha* criaItemDouble(double chave);
void inicializaPilha(struct tPilha* stack);
void push(struct tPilha* stack, struct tItemPilha* it);
struct tItemPilha* pop(struct tPilha* stack);
int buscaPilha(struct tPilha*,char);
void imprimePilha(struct tPilha* stack);



