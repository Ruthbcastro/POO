#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creando nuestra estructura
struct Clase{
	int dia;
	int horario[4];
	Clase *ptrsig;
};

//Punteros auxiliares para manipulacion de apuntadores
Clase *inicio, *nuevo, *aux;

int main() {
	//Inicializarlos en NULL
	inicio= NULL;
	nuevo=NULL;
	aux=NULL;
	
	//Menu de opciones
	int op=0;
	do{
		printf("Menu de opciones:\n");	
		printf("1.Insertar un nodo\n");		
		printf("2. Ver los datos de los nodos\n");
		printf("3. Salir\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				//verificando que no haya nodos
				if(inicio==NULL){
					
					//Creando primer nodo
					nuevo = new (Clase);
					printf("Ingresa el dia de la clase de lunes a viernes (del 1 al 5 respectivamiente): \n");
					scanf("%d", &nuevo->dia);
					printf("Ingresa la hora de entrada (del 1 al 24): \n");
					scanf("%d", &nuevo->horario[0]);
					printf("Ingresa el minuto de entrada: \n");
					scanf("%d", &nuevo->horario[1]);
					printf("Ingresa la hora de salida (del 1 al 24): \n");
					scanf("%d", &nuevo->horario[2]);
					printf("Ingresa el minuto de salida: \n");
					scanf("%d", &nuevo->horario[3]);
						
					//Manipulando punteros
					inicio=nuevo;
					aux=nuevo;
					nuevo->ptrsig=NULL;
		
					}else{

						//Creando nuevo nodo
						nuevo = new (Clase);
						printf("Ingresa el dia de la clase de lunes a viernes (del 1 al 5 respectivamiente): \n");
						scanf("%d", &nuevo->dia);
						printf("Ingresa la hora de entrada (del 1 al 24): \n");
						scanf("%d", &nuevo->horario[0]);
						printf("Ingresa el minuto de entrada: \n");
						scanf("%d", &nuevo->horario[1]);
						printf("Ingresa la hora de salida (del 1 al 24): \n");
						scanf("%d", &nuevo->horario[2]);
						printf("Ingresa el minuto de salida: \n");
						scanf("%d", &nuevo->horario[3]);
		
						//Manipulo punteros
						//Cuando el nuevo nodo es menor al inicio
						if(inicio->dia>nuevo->dia){
							nuevo->ptrsig=inicio;
							inicio=nuevo;
						}else{
							//Para insertar en otro lugar
							aux=inicio;
							//Buscar el lugar correcto para el nuevo nodo
							while(aux->ptrsig!=NULL && aux->ptrsig->dia<=nuevo->dia){
								aux=aux->ptrsig;
							}
							nuevo->ptrsig=aux->ptrsig;
							aux->ptrsig=nuevo;
						}
				//		aux->ptrsig=nuevo;
				//		aux=nuevo;
				//		nuevo->ptrsig=NULL;	
						}
				break;
				case 2:
					//Llevar a aux al inicio para comenzar a imprimir
					aux=inicio;
					
					printf("Horario de Programacion Orientada a Objetos:\n");
					
					while(aux!=NULL){
					
					//Imprimir datos de los nodos
					printf("------------------------------------\n");
					printf("Para el dia %d es de: \n", aux->dia);
					printf("%d", aux->horario[0]);
					printf(":%d", aux->horario[1]);
					printf(" - %d", aux->horario[2]);
					printf(":%d\n", aux->horario[3]);
					printf("------------------------------------\n");
					//Manipular puntero
					aux=aux->ptrsig;
					}
				break;
				case 3:
					printf("Programa terminado");
				break;
				default:
					printf("Opcion incorrecta");
			}
	}while(op!=3);

	return 0;
	system("PAUSE");		
}



//aux=inicio;
//						while(aux->ptrsig!=NULL){
//							//Manipular puntero
//							aux=aux->ptrsig;
//						}




