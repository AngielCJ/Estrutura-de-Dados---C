#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define tamanho 5

//Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt = -1;
int qtd;

//Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);

//Função principal
int main(void){
	srand(time (NULL));
	do{
		system("cls");
		lista_mostrar();
		menu_mostrar();
		scanf("%d", &opt);
		switch(opt){
			case 1:
				lista_gerar();
			break;
			case 2:
				lista_ler();
			break;
			case 3:
				lista_mostrar_ordenado();
			break;
			case 4:
				bubbleSort();
			break;
		}
	}while(opt != 0);
	system("pause");
	return 0;
}

//Mostrar o conteúdo da lista
void lista_mostrar(void){
	printf("[ ");
	for(int i = 0; i < tamanho; i++){
		printf("%d", lista[i]);
	}
	printf("]\n\n");
}
//Mostra o menu
void menu_mostrar(void)	{
	printf("1 - Gerar lista aleatoriamente\n");
	printf("2 - Criar lista manualmente\n");
	printf("3 - Ver lista ordenada\n");
	printf("4 - Aplicar metodo Bubblesort\n");
	printf("0 - Sair\n");
}

//Gera uma lista aleatória
void lista_gerar(void){
	for (int i = 0; i < tamanho; i++){
		lista[i] = rand()%9;
	}
}

//Permite que o usuário entre com os valores da lista
void lista_ler(void){
	for(int i = 0; i < tamanho; i++){
		system("cls");
		printf("Informe o valor para a posicao %d: ", i);
		scanf("%d", &lista[i]);
	}
}

//Preparar a lista para ordenação
void lista_limpar(void){
	for(int i = 0; i < tamanho; i++){
		ordenado[i] = lista[i];
	}
}

//Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void){
 	printf("[ ");
 	for (int i = 0; i < tamanho; i++ ){
 		printf("%d ", ordenado[i]);
 	}
 	printf("] Tempo = %d iteracoes\n\n", qtd);
}

//Aplica o método do bubbleSort
int bubbleSort(int vec[]){
 	int qtd, i, j, tmp;
 	qtd = 0;
 	for (i = 0; i < tamanho -1; i++){
 		for (j = i+1; j < tamanho; j++){
 			if (vec[i] > vec[j]){
 				troca(&vec[i], &vec[j]);
 			}
 			qtd++;
 		}
 	}
 return(qtd);
}

//Aplica o método SelectionSort
int selectionSort(int vec[], int tam){
	int i, j, min, qtd = 0;
	for(i = 0; i < (tam-1); i++){
		min = 1;
		for(j = (i+1); j < tam; j++){
			if(vec[j] < vec[min]) {
				min = j;
			}
			qtd++;
		}
		if (i !- min){
			troca(&ve[i], &vec[min]);
		}
	}
	return (qtd);
}

//Aplica o método InsertionSort
int insertionSort(int vec[], int tam){
	int i, j, qtd = 0;
	for(i = 1; i < tam; i++){
		j = i;
		while((vec[j] < vec[j - 1]) && (j != 0)){
			troca(&vec[j], &vec[j-1]);
			j--;
			qtd++;
		}
	}
	return(qtd);
}

//Método ShellSort
int shellSort(int vec[], int tam){
	int i, j, valor, qtd = 0;
	int gap = 1;
	do {
		gap = 3 * gap + 1;
	}while(gap < tam);
	do{
		gap /= 3;
		for(i = gap; i < tam; i++){
			valor = vec[i];
			j = i - gap;
			while (j >= 0 && valor < vec[j]){
				vec[j + gap] = vec[j];
				j -= gap;
				qtd++;
			}
			vec[j + gap] =  valor;
		}
	}while( gap > 1);
	return (qtd);
}

//Função genérica para troca de valores
void troca(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
