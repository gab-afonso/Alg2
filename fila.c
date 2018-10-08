#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Eleitor
{
	char Nome_Eleitor[100];                 //Nome do eleitor
	int Voto;                               //numero do candidato
};

struct TipoNodoFila                         //nodo que compoe a fila
{
		struct Eleitor eleitor;             //esta fila recebe o nome e o voto do eleitor
		struct TipoNodo*prox;             
};
	
struct TipoFila
{
	struct tiponodo*frente;                 //apontadores que compoem a fila
	struct tiponodo*final;
	int quantidade;                         //sera usado para quardar quantas pessoas passaram pela fila e votaram
};

	
void InicFila (struct tipofila *fila)       //incia a fila com o nodo cabeca
{
	fila->frente=(struct tiponodo*) malloc (sizeof (struct tiponodo));    
	fila->final=fila->frente;
	fila->final->prox=NULL;
	fila->quantidade=0;
	puts("iniciei a fila com alocacao dinamica de memoria");
}
	
int VaziaFila(struct tipofila fila)         //retorna se a pilha estiver vazia
{
	return (fila.frente==fila.final);
}
		
void ImprimeFila (struct tipofila fila)    //imprime quantas pessoas votaram
{
    printf("%d\n", fila.quantidade);
}

void Enfileira (struct tipofila *fila, char nome[100], int voto)     //guarda na fila o nome e o voto do eleitor
{
	fila->final->prox=(struct tiponodo*) malloc (sizeof (struct tiponodo));
	fila->final=fila->final->prox;
	strcpy(fila->final->eleitor.Nome_Eleitor, nome);
	fila->final->eleitor.voto=voto;
	fila->final->prox=NULL;
	fila->quantidade++;
	puts("enfilerei o nome e voto do eleitor que eh secreto");
}

int Desinfileira (struct tipofila *fila)    //retorna o voto do eleitor para que seja feita a contagem
{
	int salva;
	struct tiponodo *aux;
	if (vaziafila(*fila))
        puts("Impossivel desinfileirar fila esta vazia!");
    else
    {
        salva=fila->frente->prox->eleitor.voto;
        aux=fila->frente;
        fila->frente=fila->frente->prox;
        free(aux);
		printf("desinfilerei o voto: %d", salva);
		fila->quantidade--;
        return(salva);
    }
}