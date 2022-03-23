#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void swap(int menor, int j);
void mostrar(int n);
void selectionSort(int n);

int array[] = {9,7,20,40,99,50,30,1,0,-1,15,24};

int main(){    
    int tam = sizeof(array) / sizeof(int);    
    selectionSort(tam);
    mostrar(tam);
}

void mostrar(int n){
    for (int i = 0; i < n; i++){
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


void selectionSort(int n){
    for (int i = 0; i < (n-1); i++){
        int menor = i;
        for (int j = (i+1); j < n; j++) {
            if(array[j] < array[menor]){
                menor = j;
            }            
        }       
        swap(menor, i); 
    }    
}
