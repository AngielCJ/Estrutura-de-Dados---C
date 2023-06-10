//Caminhamento em Árvores Binárias

//Método Pré_Ordem
void pre_Ordem(struct NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado); //Visita o nó atual
		pre_Ordem(raiz->esq);
		pre_Ordem(raiz->dir);
	}
}

//Método Em_Ordem
void em_Ordem(struct NO* raiz){
	if(raiz){
		em_Ordem(raiz->esq);
		printf("%d \t", raiz->dado); //Visita o nó atual
		em_Ordem(raiz->dir);
	}
}

//Método Pós_Ordem
void pos_Ordem(struct NO* raiz){
	if(raiz){
		pos_Ordem(raiz->esq);
		pos_Ordem(raiz->dir);
		printf("%d \t", raiz->dado);
	}
}
