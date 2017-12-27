#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int info;
	struct tree* right;
	struct tree* left;
}no; 
//RAIZ 
no*root = NULL;

void menu();
struct tree *insere(struct tree* raiz,struct tree* aux,int v);
void preOrdem(struct tree *aux);
void inOrdem(struct tree *aux);
void posOrdem(struct tree *aux);


int main(){
	
	menu();
	preOrdem(root);
	printf("\n");
	inOrdem(root);
	printf("\n");
	posOrdem(root);
}
//Menu para INSERIR de valores
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
//Forma de INSERECAO em ARVORE
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
//Forma de EXIBICAO PREORDEM
void preOrdem(struct tree *aux){
	if(aux == NULL)
		return;
	
	if(aux->info)
		printf("%d",aux->info);
	
	preOrdem(aux->left);
	preOrdem(aux->right);	
}
//Forma de EXIBICAO INORDEM
void inOrdem(struct tree *aux){
	if(aux == NULL)
		return;
	
	preOrdem(aux->left);
	
	if(aux->info)
		printf("%d",aux->info);
	
	preOrdem(aux->right);	
}
//Forma de EXIBICAO POSORDEM
void posOrdem(struct tree *aux){
	if(aux == NULL)
		return;
	
	preOrdem(aux->left);
	preOrdem(aux->right);	

	if(aux->info)
		printf("%d",aux->info);	
}




