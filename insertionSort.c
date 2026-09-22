#include <stdio.h>

void insertionSort(int *V, int N){
    int j, atual;
    for(int i = 1; i < N; i++){
        atual = V[i];
        for(j = i; (j > 0) && (atual < V[j - 1]); j--){
            V[j] = V[j - 1];
        }
        V[j] = atual;
    }
}

int main()
{
    int vetor[5] = {9, 4, 3, 7, 10};
    
    insertionSort(vetor, 5);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}
