#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TipoNodoLista                            //nodo que compoe a lista encadeada simples
	{
		char Nome[100];                              //esta fila guarda o nome o numero e o partido de um numero indeterminado de candidatos
		int Numero;
		char Partido[5];
		int Votos;
		struct TipoNodoLista*Prox;
	};
		
struct TipoLista
	{
		struct TipoNodoLista*inicio,*final;    
	};
	
void InicLista (struct TipoLista*lista)              //inicia a lista
{
	lista->inicio=(struct TipoNodoLista*) malloc (sizeof (struct TipoNodoLista));
	lista->final=lista->inicio;
	lista->inicio->Prox=NULL;
	puts("inciei a lista com alocacao dinamica de memoria");
}

int VaziaLista (struct TipoLista lista)            //retorna se a fila esta vazia
{
	return (lista.inicio==lista.final);
}

void InsereLista (struct TipoLista *lista)   //insere  candidato na lista
{
    char nome[100];                     
	int numero;
	char partido[5];
    
	puts("digite o nome do candidato");
	scanf("%s", nome);
	puts("digite o numero do candidato");
    scanf("%d", &numero);
	puts("digite o partido do candidato");
    scanf("%s", partido);

	lista->final->Prox=(struct TipoNodoLista*) malloc (sizeof (struct TipoNodoLista));
	lista->final=lista->final->Prox;
	lista->final->Votos=0;                 //inicia a contagem de votos
	strcpy(lista->final->Nome, nome);
	printf("inseri %s na lista\n",nome);
	lista->final->Numero=numero;
	printf("inseri %d na lista\n",numero);
	strcpy(lista->final->Partido, partido);
	printf("inseri %s na lista\n", partido);
	lista->final->Prox=NULL;
}

int RemovePosicao (struct TipoLista *lista,struct TipoNodoLista *posicao)     //remove um candidato da lista
{
	int salva_numero;
	char salva_partido;
	char salva_nome;
	struct TipoNodoLista *aux;
	if (posicao==lista->final)
		puts("Impossivel, nao ha candidato nesta posicao!");
	else
		if (VaziaLista(*lista))
			puts("Impossivel remover, lista esta vazia!");
		else
			if (posicao==NULL)
				puts("Impossivel, esta posicao nao existe");
			else
		aux=posicao->Prox;
		salva_numero=aux->Numero;
        strcpy(salva_nome, aux->Nome);
        strcpy(salva_partido, aux->Partido);
		posicao->Prox=aux->Prox;
		free(aux);	
		printf("removi o candidato %s da lista",salva_nome);
        return (salva);
}

void ImprimeLista (struct TipoLista lista)                                   //mostra a lista
{
	struct TipoNodoLista *aux;
	if (VaziaLista(lista))
		puts("listavazia");
	else
         for (aux=lista.inicio->Prox; aux!=NULL; aux=aux->Prox)
		{
            printf("candidato %s  \n", aux->Nome);
			printf("numero %d \n", aux->Numero);
			printf("do partido %s \n", aux->Partido);
			printf("obteve o %d votos\n", aux->Numero);
		}
       
}

void BuscaCandidato(struct TipoLista *lista,int voto);
{
	struct tiponodo *aux;
	aux=lista->inicio->prox;
	while (voto!=aux->Numero || aux=NULL)
		aux=aux->prox;
	if (aux=NULL)
		puts("candidato nao existe");
	else
		aux->votos++;	
}