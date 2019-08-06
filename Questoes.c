#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Math.h>
#include "Fila.h"
#include "Pilha.h"
#include "Lista.h"
#include "Questoes.h"


void questao1()
{
    printf("Questao 1\n");

    int tam;
    char n;
    struct tLista lista;
    novaLista(&lista); // Inicializando lista

    printf("Tamanho da lista: ");
    scanf("%d",&tam);
    fflush(stdin);

    while(tam > 0) // Inserir quantidade desejada de elementos na lista
    {
        printf("Valor a inserir: ");
        scanf("%c", &n);
        insereFinalLista(&lista, criaItemLista(n));
        tam--;
        fflush(stdin);
    }
    printf("Lista atual: ");
    imprimeLista(&lista);

    // Inicializar pilha que irá inverter a lista
    struct tPilha stack;
    inicializaPilha(&stack);

    // agora, percorreremos a lista, inserindo cada elemento na pilha
    struct tItemLista* i;
    for(i=lista.primeiro; i!=NULL; i=i->prox)  // percorre lista, iniciando do primeiro item, e seguindo pelo ponteiro prox
    {
        push(&stack, criaItem(i->it));
    }
    printf("\n");

    // O primeiro item a ser mostrado da pilha (topo) será o ultimo da lista, o segundo da pilha será o penultimo, e assim por diante
    // estaremos mostrando de forma inversa
    printf("Lista invertida: ");
    imprimePilha(&stack);
}

void questao2(){
    printf("Questao 2\n");

    int j;
    char ch, str[100000];
	struct tPilha pilha;

    printf("Expressao posfixa (numeros de apenas um digito): ");
    scanf("%s", str);

    inicializaPilha(&pilha);

    for(j=0; j<strlen(str); j++) // Percorre expressao lida
    {
        if(str[j] >= '0' && str[j] <= '9') // verifica se é um numero, se for, empilha
        push(&pilha, criaItemDouble(str[j]-'0'));


        // caso seja um operador matemático, tirar os dois últimos números da pilha e realizar operação
        // isso garante que a ordem posfixa seja mantida, empilhando o resultado de volta
        if(str[j] == '*' || str[j] == '/' || str[j] == '-' || str[j] == '+' )
        {
            double a, b;

            struct tItemPilha * item = pop(&pilha);     //tirar elemento do topo
            a = item->valor;
            item = pop(&pilha);                         //tirar elemento do topo
            b = item->valor;

            //inserir elemento novo, realizando operacao
            if(str[j] == '*') push(&pilha, criaItemDouble((b * a)));
            if(str[j] == '/') push(&pilha, criaItemDouble((b / a)));
            if(str[j] == '+') push(&pilha, criaItemDouble((b + a)));
            if(str[j] == '-') push(&pilha, criaItemDouble((b - a)));


        }
    }
    struct tItemPilha * item = pop(&pilha);
        printf("Resultado: %.2f",item->valor);

}

void questao3()
{
    printf("Questao 3\n");

    int i, j, n, valido;
	char ch, str[100000];
	struct tPilha pilha;
	valido = 1;

    printf("Expressao: ");
    scanf("%s", str);

    // Converter /* (47 e 42) ou */ (42 e 47) para um único character para facilitar o trabalho. Usamos -1, e -2.
    for(j=0; j<strlen(str); j++)
    {
        if(j+1 < strlen(str) &&  str[j]==47 && str[j+1] == 42 ) { // Se /*
            str[j] = -1;                                         // Substuir character por -1
            memmove(&str[j+1], &str[j+2], strlen(str) - (j+1));  // Remover *
        }
        else if(j+1 < strlen(str) &&  str[j]==42 && str[j+1] == 47) { // Se */
            str[j] = -2;                                              // Substuir character por -2
            memmove(&str[j+1], &str[j+2], strlen(str) - (j+1));       // Remover /
        }
    }
    printf("\n%s", str);

    inicializaPilha(&pilha);                                        // Usaremos a pilha
    for(j=0, valido=1; j<strlen(str) && valido==1; j++)
    {
        if(str[j]=='(' || str[j]=='[' || str[j]=='{' || str[j]==-1) // Empilhar caso uma expressão seja aberta
        {
            push(&pilha, criaItem(str[j]));
        }
        if(str[j]==')' || str[j]==']' || str[j]=='}' || str[j]==-2) // Caso uma expressão seja fechada, desempilhar e checar se ela foi aberta
        {
            if(pilha.topo==NULL) valido=0;                          // Checar se há elemento na pilha, caso contrário, não foi aberta
            else{
                struct tItemPilha * item = pop(&pilha);             // Se tiver elemento, checar se é uma abertura correspondente ao fechamento
                char ch = item->chave;                              // () ou [] ou {} ou -1 com -2, nossa conversão de /**/
                if(ch=='(' && str[j]!=')') valido=0;
                if(ch=='[' && str[j]!=']') valido=0;
                if(ch=='{' && str[j]!='}') valido=0;
                if(ch==-1 && str[j]!=-2)   valido=0;
            }
        }
    }
    if(pilha.topo == NULL && valido) printf("valido\n");           // Se não houver aberturas na pilha e a expressao for valida, mostrar valido
    else printf("Invalido\n");
}

void questao4()
{
    printf("Questao 4\n");

	char ch;
	struct tPilha pilha, pilhaInversa;

	inicializaPilha(&pilha);
	inicializaPilha(&pilhaInversa);

    printf("Expressao: ");

    struct tItemPilha * i;
    while((ch=getche()) != '\r'){
        push(&pilhaInversa, criaItem(ch));    // empilha caracteres na pilha com o texto invertido
    }

    for(i=pilhaInversa.topo; i!=NULL; i=i->anterior) // percorre a partir do topo, seguindo para o elemento anterior, até chegar na base
    {
        push(&pilha, criaItem(i->chave));            // empilha caracteres na outra pilha, de forma que o ultimo esteja na base, o penultimo esteja uma posição acima, e assim por diante
    }

    printf("\nNormal: ");
    for(i=pilha.topo; i!=NULL; i=i->anterior) // percorre a partir do topo, seguindo para o elemento anterior, até chegar na base, imprimindo o texto
    {
        printf("%c", i->chave);
    }

    printf("\nInverso: ");
    for(i=pilhaInversa.topo; i!=NULL; i=i->anterior) // percorre a partir do topo, seguindo para o elemento anterior, até chegar na base, imprimindo o texto invertido
    {
        printf("%c", i->chave);
    }
    printf("\n");

    int palindrome = 1;

    // Aqui, as duas pilhas terão elementos removidos e comparados, para verificar se é palindrome
    while(pilha.topo != NULL){

        struct tItemPilha * it1 = pop(&pilha); //obter primeira letra
        while(it1 != NULL && (it1->chave == ' ' || it1->chave == '.' )) it1 = pop(&pilha);         //ignorar pontos e espaços
        struct tItemPilha * it2 = pop(&pilhaInversa); // obter ultima letra
        while(it2 != NULL && (it2->chave == ' ' || it2->chave == '.' )) it2 = pop(&pilhaInversa);  //ignorar pontos e espaços

        if(it1 != NULL && it2 != NULL)if(it1->chave != it2->chave) palindrome = 0; // comparar primeira com a ultima
    }

    if(palindrome) printf("\nE um Palindromo!");
    else printf("\nNao palindromo.");


}

void questao5()
{
    printf("Questao 5\n");
    char opc;
    int prioridade;
    struct tFila queue;
    struct tItemFila it;
    queue=inicializaFila(10);

    printf("Digite 1 para inserir um novo documento ou 2 para imprimir fila. Qualquer outra coisa para sair: ");
    while((opc=getche())!='3')
    {

        if(opc=='1')
        {
            fflush(stdin);
            printf("\nQual o cargo? 1 - Diretor, 2 - Coordenador e 3 - Funcionario\n");
            scanf("%d", &prioridade);
            it.prioridade = prioridade; // conversao para int

            fflush(stdin);
            printf("\nNome do documento para imprimir (um caractere): ");
            scanf("%c", &it.chave);         // caractere apenas para indentificar o documento
            enqueuePrioridade(&queue, it);  // Inserir na fila de acordo com a prioridade
        }
        if(opc=='2') {
            printf("\nImprimindo fila de impressao...\n");
            int i;
            while(queue.inicio!=queue.fim) // Verificar se fila não está vazia
            {
                struct tItemFila it = dequeue(&queue);  // Caso tenha elementos na fila, retirar o primeiro elemento (de maior prioridade)
                printf("--- Impresso documento %c (prioridade %d)\n", it.chave, it.prioridade); // mostrar na tela o elemento removido (impresso)
            }
            system("pause");
        }
        fflush(stdin);
        system("cls");
        printf("Digite 1 para inserir um novo documento ou 2 para imprimir fila. Qualquer outra coisa para sair: ");

    }
}

void questao6()
{
    printf("Questao 6\n");

    int j;
    int discos;
	struct tPilha pilha1;
	struct tPilha pilha2;
	struct tPilha pilha3;

    printf("Numero de discos: ");
    scanf("%d", &discos);

    // Usaremos 3 pilhas para o jogo da torre de hanoi
    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);
    inicializaPilha(&pilha3);
    pilha1.nome = 'A';
    pilha2.nome = 'B';
    pilha3.nome = 'C';


    // Inserir discos de baixo pra cima, do maior para o menor, na pilha
    int tam = discos;
    while(tam > 0)
    {
        push(&pilha1, criaItemInt(tam));
        tam--;
    }


    // formula conhecida, que diz quantos movimentos serao necessarios para resolver torre
    int movimentos = pow(2, discos) - 1;


    if(discos > 0)
    {
        int i = 1;
        for(i = 1; i <= movimentos; i++)
        {
            // Movimentos de acordo com a quantidade de movimentos restante
            // Há uma ordem: O primeiro movimento é mover da origem para o destino (i%3 == 1)
            // O primeiro movimento é mover da origem para a torre auxiliar (i%3 == 2)
            // Por fim, o terceiro movimento é mover da torre auxiliar para o destino (i%3 == 1)
            // Isso se repetirá sempre, como acontece a seguir
            if (i%3 == 1) moverDiscos(&pilha1,&pilha2);
            else if(i%3 == 2) moverDiscos(&pilha1,&pilha3);
            else if(i%3 == 0) moverDiscos(&pilha3,&pilha2);
        }
    }

}

// Mover disco entre duas pilhas
void moverDiscos(struct tPilha *a,  struct tPilha *b, char discoA, char discoB)
{
    // Disco no topo de A
    struct tItemPilha * topoA = NULL;
    if(a->topo != NULL) topoA = pop(a);

    // Disco no topo de B
    struct tItemPilha * topoB = NULL;
    if(b->topo != NULL) topoB = pop(b);

    // Se pino A estiver vazio,
    if (topoA == NULL)
    {
        printf("1 ");
        push(a, topoB); // Basta mover diretamente o pino do topo de B para A
        printf("Disco %d movido da pilha %c para a pilha %c\n", topoB->disco, b->nome, a->nome);
    }
    // Se pino B estiver vazio
    else if (topoB == NULL)
    {
        printf("2 ");
        push(b, topoA); // Basta mover diretamente o pino do topo de A para B
        printf("Disco %d movido da pilha %c para a pilha %c\n", topoA->disco, a->nome, b->nome);
    }
    // Se o disco no topo do pino 1 for maior que o topo do pino 2
    else if (topoA->disco > topoB->disco)
    {
        printf("3 ");
        push(a, topoA); // Colocar de volta no lugar o topo do pino 1, e depois
        push(a, topoB); // inserir o antigo topo de B, que é menor
        printf("Disco %d movido da pilha %c para a pilha %c\n", topoB->disco, b->nome, a->nome);
    }
    // Caso contrario
    else if(topoA->disco <= topoB->disco)
    {
        printf("4");
        push(b, topoB); // Color topo de B de volta, e depois
        push(b, topoA); // inserir no pino B o antigo topo de A, que é menor
        printf("Disco %d movido da pilha %c para a pilha %c\n", topoA->disco, a->nome, b->nome);
    }

}
