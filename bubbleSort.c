#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int *V, int N){
    int continuar;
    do{
        continuar = 0;
        for(int i = 0; i < N - 1; i++){
            if(V[i] > V[i + 1]){
                troca(&V[i], &V[i + 1]);
                continuar = i;
            }
        }
        N--;
    }while(continuar != 0);
}

int main()
{
    int vetor[5] = {5, 4, 3, 2, 1};
    
    bubbleSort(vetor, 5);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}
