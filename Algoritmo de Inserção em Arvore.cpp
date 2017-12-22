#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int info;
	struct tree* right;
	struct tree* left;
}no; 

no*root = NULL;

void menu();
struct tree *insere(struct tree* raiz,struct tree* aux,int v);

int main(){
	
	menu();
	
}

void menu(){
	int valor;
	int opcao = 1;
	
	do{
		printf("Informe um numero: ");
		scanf("%d",&valor);
		
		if(root == NULL)
			root = insere(root, root, valor);
		else
			insere(root, root, valor);
		
		printf("Deseja continuar? <1> SIM | <qualquer outro> NAO\n");
		scanf("%d",&opcao);
	}while(opcao == 1);
	
}

struct tree *insere(struct tree* raiz,struct tree* aux,int v){
	if(aux == NULL){
		aux = (struct tree*)malloc(sizeof(struct tree));
		if(aux == NULL){
			printf("Memoria Cheia");
			exit(0);
		}
		aux->right = NULL;
		aux->left = NULL;
		aux->info = v;
		if(root == NULL)
			return aux;
		if(raiz->info > aux->info)		
			raiz->left = aux;
		else
			raiz->right = aux;
		
		return aux;
	}
	if(aux->info > v)
		return insere(aux, aux->left, v);
	else
		return insere(aux, aux->right, v);
	
}




