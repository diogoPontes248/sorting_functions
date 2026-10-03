#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//O método consiste em a cada iteração do while, mover o maior elemento para a última posição do vetor
//Complexidade: O(n^2)
void bubbleSort(int *v, int n){
    int continuar;
    do{
        continuar = 0;
        for(int i = 0; i < n - 1; i++){
            if(v[i] > v[i + 1]){   
                troca(&v[i], &v[i + 1]);
                continuar = i;
            }
        }
        n--;
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
