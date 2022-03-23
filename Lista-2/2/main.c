#include <stdio.h>

int main(){

    int n = 3;
    int count = 0;

    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            for (int k = 1; k <= j; k++){
                count++;
            }            
        }
    }

    printf("%d\n", count);
}