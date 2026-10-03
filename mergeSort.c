#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Método sofisticado para ordenação utilizando o principio de divisão e conquista.
//Utiliza a recursão para ordenar subvetores até ordenar o vetor inteiro.
//Complexidade: sempre O(n*log(n))
void merge(int *v, int inicio, int meio, int fim){
    //Ao me referir a dois vetores, estou indicando a primeira metade do vetor v e a segunda metade como vetores diferentes
    //temp = vetor temporario para guardar os elementos ordenados
    //p1 e p2 = indices atuais de cada um dos vetores
    //tamanho = o tamanho da soma dos dois vetores
    int *temp, p1, p2, tamanho;
    //valores booleanos para verificar se um ou ambos os vetores foram percorridos inteiros.
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(int i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                //pega o menor elemento entre os dois vetores
                if(v[p1] < v[p2]){
                    temp[i] = v[p1++];
                }
                else{
                    temp[i] = v[p2++];
                }
                
                //verificam se algum dos vetores acabou
                if(p1 > meio){
                    fim1 = 1;
                }
                if(p2 > fim){
                    fim2 = 1;
                }
            }
            else{
                //se já acabou um dos vetores, apenas copia o resto do outro vetor
                if(!fim1){
                    temp[i] = v[p1++];
                }
                else{
                    temp[i] = v[p2++];
                }
            }
        }
        //transfere o vetor ordenado para o vetor original.
        for(int j = 0, k = inicio; j < tamanho; j++, k++){
            v[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim) / 2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main()
{
    int vetor[5] = {5, 4, 3, 2, 1};
    
    mergeSort(vetor, 0, 4);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}