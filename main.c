int main()
{
	InicLista(&lista_candidatos);
	puts("Deseja inserir um candidato a lista? s/n");
	scanf("%c", a);
	while (a!="n") 
	{
		InsereLista(&lista_candidatos);
		puts("Deseja inserir um candidato a lista?  s/n");
		scanf("%c", a);
	}
	ImprimeLista(lista_candidatos);
	
	InicFila(&fila_eleitores);
	InicPilha(&pilha_comprovantes);
	puts("Alguem vai entrar na fila?  s/n");
	scanf("%c", a);
	while (a!=n) 
	{
		Enfileira(&fila_eleitores);
		puts("mais alguem vai entrar na fila? s/n");
		scanf("%c", a);
	}
	salva_quantidade=fila_eleitores->quantidade;
	puts("agora, começaremos a votacao!");
	while (fila_eleitores->quantidade!=0)
	{
		Push(&pilha_comprovantes,fila_eleitores->Eleitor.Nome_Eleitor);
		VOTO=desenfileira(&fila_eleitores);
		BuscaCandidato(&lista_candidatos,VOTO);            //adiciona o voto ao candidato
	}
	printf("o numero total de votos foi %d", salva_quantidade);
	puts("apuracao dos votos");
	ImprimeLista(lista_candidatos);
	
}