
#include <stdio.h>
#include <stdlib.h>

#define TamMax 300


struct TipoPilha               //Pilha implementada em vetor
{
	char Vetor[TamMax][100];       //a pilha tem capacidade para (adcionar valor aqui) comprovantes de votos
	int Topo;
};

void InicPilha (struct TipoPilha *pilha)   //inicia a pilha como o topo=0
{
	pilha->Topo=0;
	printf("iniciei a pilha que pode ter no maximo %d elementos", Tam_Max-1);
}

int VaziaPilha (struct TipoPilha *pilha)  //verifica se a pilha nao contem nenhum comprovante
{
	return(pilha->Topo==0);
}

void Push (struct TipoPilha *pilha,char Nome[100])   //adiciona um comprovante de voto á pilha
{
	if (pilha->Topo==TamMax-1)
		puts("ERRO: impossivel adicionar a pilha esta cheia!");
	else
	{
		strcpy(pilha->vetor[pilha->Topo], Nome);
		pilha->Topo++;
		printf("adicionei %s na pilha", Nome);
	}
}

int Pop (struct TipoPilha *pilha)                    //remove o comprovante do topo da pilha
{
    if (VaziaPilha(pilha))
		puts("ERRO: Impossivel pilha esta vazia");
    else
    {
        pilha->Topo--;
		printf("retirei o comprovante do eleitor %s da pilha", pilha->vetor[pilha->topo]);
        return(pilha->vetor[pilha->Topo]);
    }   
}

int TamanhoPilha (struct TipoPilha *pilha)        //retorna o tamanho da pilha
{
	prinf("a pilha tem atualmente tamanho: %d", pilha->topo);
	return (pilha->Topo);
}

void ImprimePilha (struct TipoPilha pilha)       //imprime a pilha de respeitando o TAD
{
	int i;
	for (i=TamMax-1; i!=-1; i--;)
		printf('%s \n', pilha.vetor[i]);
}