#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//Método de ordenação sofisticado que simula uma estrutura de árvore binária completa.
//Complexidade: sempre O(n*log(n)).
void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2 * pai + 1;
    while(filho <= fim){
        if(filho < fim){
            if(v[filho] < v[filho + 1]){
                filho++;
            }
        }
        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2 * pai + 1;
        }
        else{
            filho = fim + 1;
        }
    }
    v[pai] = aux;
}

void heapSort(int *v, int n){
    for(int i = (n - 1) / 2; i >= 0; i--){
        criaHeap(v, i, n - 1);
    }
    for(int i = n - 1; i >= 1; i--){
        troca(&v[0], &v[i]);
        criaHeap(v, 0, i - 1);
    }
}

int main()
{
    int vetor[5] = {5, 4, 3, 2, 1};
    
    heapSort(vetor, 5);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}