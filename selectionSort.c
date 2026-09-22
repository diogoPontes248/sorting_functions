#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int *V, int N){
    int menor;
    for(int i = 0; i < N - 1; i++){
        menor = i;
        for(int j = i + 1; j < N; j++){
            if(V[j] < V[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca(&V[i], &V[menor]);
        }
    }
}

int main()
{
    int vetor[5] = {5, 4, 3, 2, 1};
    
    selectionSort(vetor, 5);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}
