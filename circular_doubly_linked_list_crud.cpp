#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char dato [50];
	struct nodo *sig;
	struct nodo *ant;
};

nodo *primero=NULL;
nodo *ultimo=NULL;

void insertar ();
void buscar ();
void eliminar ();
void modificar ();
void mostrar ();

int main (){
	
	int op;
	
	do{
		printf("Que operacion realizaras\n");
		printf("1) Insertar\n");
		printf("2) Buscar\n");
		printf("3) Eliminar\n");
		printf("4) Modificar\n");
		printf("5) Mostrar\n");
		printf("6) Salir\n");
		scanf("%d", &op);
		
		switch(op){
			
			case 1:
				insertar();
				break;
				
				case 2:
				buscar();
				break;
				
				case 3:
				eliminar();
				break;
				
				case 4:
				modificar();
				break;
				
				case 5:
				mostrar();
				break;
				
				default:
				printf("\nADIOS");
				break;
		}
	}while(op<6);
}

void insertar(){
	
	nodo *nuevo=(nodo*)malloc(sizeof(nodo));
	
	printf("\nIngresa el video\n");
	fflush(stdin);
	gets(nuevo->dato);
	printf("\n");
	
	if(primero==NULL){
		primero=nuevo;
		primero->sig=primero;
		ultimo=primero;
		primero->ant=ultimo;	
	}
	else
		ultimo->sig=nuevo;
		nuevo->sig=primero;
		nuevo->ant=ultimo;
		ultimo=nuevo;
		primero->ant=ultimo;
}

void buscar(){

	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	
	char nodoBuscado [50];
	int encontrado=0;
	
	if(primero!=NULL){
		
	printf("\nVideo a buscar\n");
	fflush(stdin);
	gets(nodoBuscado);
	
		do{
			if(strcmp(actual->dato,nodoBuscado)==0){
				printf("\nSe a encontardo el video: %s\n\n", actual->dato);
				encontrado=1;			
			}
			actual=actual->sig;
		}while(actual!=primero&&encontrado!=1);

		if(encontrado==0){
			printf("\nNo existe el video\n\n");
			}
		}
	else
		printf("\nLa lista esta vacia\n\n");
	}

void modificar(){
	
	struct nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	
	char nodoBuscado [50];
	int encontrado=0;
	
	if(primero!=NULL){
		
	printf("\nVideo a buscar\n");
	fflush(stdin);
	gets(nodoBuscado);
	
		do{
			if(strcmp(actual->dato,nodoBuscado)==0){
				printf("\nSe a encontardo el video\n");
				printf("\nIngresa el nuevo video\n");
				fflush(stdin);
				gets(actual->dato);
				printf("\n");
				encontrado=1;
			}
			actual=actual->sig;
		}while(actual!=primero&&encontrado!=1);
		
		if(encontrado==0){
		printf("\nNo existe el video\n\n");
	}
}
	else{
		printf("\nLa lista esta vacia\n\n");
	}
}

void eliminar(){
	
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	nodo *ant2=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	ant2=NULL;
	
	char nodoBuscado[50];
	int encontrado=0;
		
	if(primero!=NULL){
	
	printf("\nIngresa el video a buscar para eliminarlo\n");
	fflush(stdin);
	gets(nodoBuscado);
		
		do{
			if(strcmp(actual->dato,nodoBuscado)==0){
				printf("\nVideo encontrado\n");
				if(actual==primero){	
				primero=primero->sig;
				primero->ant=ultimo;
				ultimo->sig=primero;
			}
			else if(actual==ultimo){
				ultimo=ant2;
				ultimo->sig=primero;
				primero->ant=ultimo;
			}else{
				ant2->sig=actual;
				actual->sig->ant=ant2;
			}
			printf("\nVideo eliminado con exito\n\n");
			encontrado=1;
	}
		ant2=actual;
		actual=actual->sig;
}while(actual!=primero&&encontrado!=1);

	if(encontrado==0){
			printf("\nVideo no enconrado\n\n");
	}
		else
			free(ant2);
	}
	else{
		printf("\nLa lista esta vacia\n\n");
	}
}

void mostrar(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL){
		do{
			printf("\n%s",actual->dato);
			actual=actual->sig;
		}while (actual!=primero);
	printf("\n\n");	
	}
	else{
		printf("\nLa lista esta vacia\n\n");
	}
}
