//Função de árvore binária de busca
int buscaArvoreBinaria(int vec[], int arg, int tam){
	int no, achou, fim;
	fim = 0;
	no = 0;
	achou = -1;
	while(achou == -1) && (fim < tam){
		if(arg == vec[no]){
			achou = no;
		}
		if (arg < vec[no]){
			no = (2 * no) + 1;
		}
		else{
			no = (2 * no) + 2;
		}
		fim++;
	}
	return (achou);
}