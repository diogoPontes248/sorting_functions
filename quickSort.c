#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//Método de ordenação sofisticado que utiliza a recursão e o princípio da divisõa e conquista.
//Seu método consistem em particionar o vetor utilizando um elemento chamado pivo.
//Esse pivo servirá para particionar o vetor em dois vetores: um contendo todos os elementos menores que o pivo,
//e outro com os elementos maiores que o pivo.
//Em seguida, particiona novamente esses dois novos vetores, até a ordenação ficar completa.
//Complexidade: O(n*log(n)) no melhor caso e caso médio, e O(n^2) no pior caso.
int particiona(int *v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo){
            esq++;
        }
        while(v[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            troca(&v[esq], &v[dir]);
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int *v, int inicio, int fim){
    int pivo;
    if(inicio < fim){
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}

int main()
{
    int vetor[5] = {5, 4, 3, 2, 1};
    
    quickSort(vetor, 0, 4);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}