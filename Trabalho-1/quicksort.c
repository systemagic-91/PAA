#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int menor, int j);
void quickS(int n);
void quickSort(int i, int j);
void mostrar(int n);

//int array[] = {9,7,20,40,99,50,30,1,0,-1,15,24,33,58,15,16};
//int array[] = {9,7,20,40,99,50,30,1,0,-1};
int comparacoes = 0;

// int array[100000];
// int array[250000];
int array[500000];


int main(){    

   for (int i = 0; i < 500000; i++){
      array[i] = rand() % 100000;
   }

   int tam = sizeof(array) / sizeof(int);

   clock_t t = clock();   

   quickS(tam);

   t = clock() - t;    

   //printf("Numero de comparações: %d\n", comparacoes);

   printf("\nTempo de execução: %lfseg\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
   //  mostrar(tam);
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

      comparacoes++;
      while(array[i] < pivo){         
         i++;
         comparacoes++;
      }

      comparacoes++;
      while(array[j] > pivo){         
         j--;
         comparacoes++;
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