#include <stdio.h>

//O método consiste em ordenar o vetor igual ordenamos uma mão de baralho.
//Inserindo cada elemento em sua posição e "deslizando" as cartas odenadas em sua frente para as posições seguintes.
//complexidade: O(n^2) sendo melhor que o selection sort na prática.
void insertionSort(int *v, int n){
    int j, atual;
    for(int i = 1; i < n; i++){
        atual = v[i];
        for(j = i; (j > 0) && (atual < v[j - 1]); j--){
            v[j] = v[j - 1];
        }
        v[j] = atual;
    }
}

int main()
{
    int vetor[5] = {5, 4, 3, 2, 1};
    
    insertionSort(vetor, 5);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}
