#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//O método consiste em colocar cada elemento na sua posição de maneira crescente.
//Ou seja, na primeira iteraçãa, o algoritmo irá encontrar o menor elemento e coloca-lo na primeira posição.
//Em seguida, ele irá achar o menor elemento do vetor restante, a parte do vetor que ainda não está ordenado.
//Complexidade: O(n^2) sendo melhor que o bubble sort na prática.
void selectionSort(int *v, int n){
    int menor;
    for(int i = 0; i < n - 1; i++){
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca(&v[i], &v[menor]);
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
