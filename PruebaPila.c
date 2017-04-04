/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
 
typedef struct pila{ 
    int clave;
    struct pila *psig;
}pila;

typedef struct aux{ 
    char caracter;
    struct aux *psig_aux;
}aux;
 
pila *pmaestro;
/*Declaración de funciones*/
pila *NuevoElem();
void push(int dato);
int pop(void);
void imprimir(pila *);

aux *pmaestroaux;
/*Declaración de funciones*/
aux *NuevoElemaux();
void pushaux(char car);
char popaux(void);
void imprimiraux(aux *);
/*Fin de las declaraciones*/
 
 
/*******************************FUNCION MAIN*****************************/
 
int main(int argc, char** argv){
  char m, c;
  int k;
  printf("Para la pila. Anadir un elemento [Q], borrar el ultimo elemento [W], listar todo [E] o salir [R]: \n\n");
  printf("Para Aux. Anadir un elemento [A], borrar el ultimo elemento [S], listar todo [D] o salir [R]: \n\n");
  do{
    printf("[Q], [W], [E] o [R] para la pila y [A], [S], [D], [R] para Aux: ");
    m=getchar();
    getchar();
 
    switch(m){
        case 'Q': printf("Introduzca un número: "); scanf("%d", &k); getchar(); push(k); break;
        case 'W': pop(); break;
        case 'E': imprimir(pmaestro); break;
        
        
        case 'A': printf("Introduzca el caracter: "); scanf("%c", &c); getchar(); pushaux(c); break;
        case 'S': popaux(); break;
        case 'D': imprimiraux(pmaestroaux); break;
        
        case 'R': exit(0);       
        default: puts("\nSaliendo del programa...");
  
        return 0;
    }
  }while(m != 'Q'|| m != 'W' || m != 'E' || m != 'A' || m != 'S'|| m != 'D' || m != 'R' );
}
 
/**************************************************************************/
 /*Añade un nuevo elemento a la pila*/
void push(int dato) { 
    pila *q = NuevoElem();
    q->psig = pmaestro;
    q->clave = dato;
    pmaestro = q;
}
 /*Esta función "desecha" el último elemento introducido*/
int pop(void) { 
    pila *q; 
    int x;
    if (pmaestro==NULL) { 
        puts("Lista vac¡a"); 
        return EOF;
    }
    else{
        x = pmaestro->clave;
        q = pmaestro;
        pmaestro = pmaestro->psig;
        free(q);
        return x;
    }
}
 /*Crea un nuevo elemento. Atento: retorna un puntero*/
pila *NuevoElem() { 
    pila *q = (pila *)malloc(sizeof(pila));
    if (q==NULL) { printf("Falta memoria"); exit(0);}
        return q;
}
 /*Imprime todos los datos albergados en la pila hasta el momento*/
void imprimir(pila *pmaestro) {
    printf("Los numeros son: ");
    while(pmaestro!=NULL){
        printf("%d ", pmaestro->clave);
        pmaestro = pmaestro->psig;
    }
    printf("\n");
}




void pushaux(char car) { 
    aux *q = NuevoElemaux();
    q->psig_aux = pmaestroaux;
    q->caracter = car;
    pmaestroaux = q;
}
 /*Esta función "desecha" el último elemento introducido*/
char popaux(void) { 
    aux *q; 
    char x;
    if (pmaestroaux == NULL) { 
        puts("Lista vac¡a"); 
        return EOF;
    }
    else{
        x = pmaestroaux->caracter;
        q = pmaestroaux;
        pmaestroaux = pmaestroaux->psig_aux;
        free(q);
        return x;
    }
}
 /*Crea un nuevo elemento. Atento: retorna un puntero*/
aux *NuevoElemaux() { 
    aux *q = (aux *)malloc(sizeof(aux));
    if (q==NULL) { printf("Falta memoria"); exit(0);}
        return q;
}
 /*Imprime todos los datos albergados en la pila hasta el momento*/
void imprimiraux(aux *pmaestroaux) {
    printf("Las claves introducidas son: ");
    while(pmaestroaux!=NULL){
        printf("%c ", pmaestroaux->caracter);
        pmaestroaux = pmaestroaux->psig_aux;
    }
    printf("\n");
}