#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void swap(int menor, int j);
void mostrar(int n);
void heapSort(int tam);
void constroi(int tam);
void reconstroi(int tam);
int getMaiorFilho(int i, int tam);

int array[] = {0,7,20,40,99,50,30,1,0,-1,15,24,9};

int main(){    
    int tam = sizeof(array) / sizeof(int);    
    heapSort(tam);
    mostrar(tam);
}

void mostrar(int n){
    for (int i = 1; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * Troca elementos da lista de posicao.
 * @param a - indice (inteiro)
 * @param b - indice (inteiro)
 */
void swap(int a, int b){  

   int tmp = array[b];
   array[b] = array[a];
   array[a] = tmp;
}


void heapSort(int n){

    for (int t = 2 ; t <= n ; t++){
        constroi(t);
    }

    int t = n;

    while(t > 1){
        swap(1, t--);
        reconstroi(t);
    }
}


void constroi(int tam){
    for (int i = tam ; i > 1 && array[i] > array[i/2] ; i /=2){
        swap(i, i/2);
    }
}

void reconstroi(int tam){
    
    int i = 1;
    int filho;

    while (i <= (tam/2)){

        filho = getMaiorFilho(i, tam);

        if(array[i] < array[filho]){

            swap(i, filho);
            i = filho;

        } else {
            i = tam;
        }
    }
}


int getMaiorFilho(int i, int tam){
    
    int maior = 0;

    if((i * 2) == tam || array[i * 2] > array[(i * 2) + 1]){
        maior = i * 2;
    } else {
        maior = (i * 2) + 1;
    }

    return maior;
}


