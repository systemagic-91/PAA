#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void swap(int menor, int j);
void quickS(int n);
void quickSort(int i, int j);
void mostrar(int n);

int array[] = {9,7,20,40,99,50,30,1,0,-1,15,24};


int main(){    
    int tam = sizeof(array) / sizeof(int);
    quickS(tam);
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


/**
 * Chamada do Quicksort.
 */
void quickS(int n){
   quickSort(0, (n - 1));
}


/**
 * Ordenacao por Quicksort. 
 * @param esq - inicio array
 * @param dir - final  array
 */
void quickSort(int esq, int dir){

   int i = esq;
   int j = dir;

   int pivo = array[(dir+esq)/2];

   while(i <= j){

      while(array[i] < pivo){         
         i++;
      }

      while(array[j] > pivo){         
         j--;
      }     

      if(i <= j){
         swap(i, j);
         i++;
         j--;
      }
   }

   if(esq < j){       
      quickSort(esq, j);
   }

   if(i < dir){       
      quickSort(i, dir);
   }
}