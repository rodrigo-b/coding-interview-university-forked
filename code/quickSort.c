#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void shuffleArray(int *array, int size){

    for ( int i = 0; i < size; i ++){
        int  t = rand() / RAND_MAX / (size - i) + 1;
        int aux = array[i];
        array[i] = array[t];
        array[t] = aux;
    }
}

int partitioning(int *array,int init,int size){

    int positionInit = init;
    int positionFinal = size + 1;

    while(true){

        while(array[++positionInit] < array[init]){
            if(positionInit == size){
                break;
            }
        }

        while(array[--positionFinal] > array[init]){
            if(positionFinal == init){
                break;
            }
        }

        if(positionInit >= positionFinal){
            break;
        }

        int aux = array[positionFinal];
        array[positionFinal] = array[positionInit];
        array[positionInit] = aux;
    }

    int aux = array[positionFinal];
    array[positionFinal] = array[init];
    array[init] = aux;
    return positionFinal;
}


void quickSort(int *array,int lo,int hi){

    if(hi <= lo){
        return;
    }

    int pivotPosition = partitioning(array, lo, hi);
    quickSort(array, lo , pivotPosition - 1);
    quickSort(array,pivotPosition + 1,hi);
}

int main (){

    int array [] = {2,8,22,33,6,9,3,21,22,90,60};

    shuffleArray(array, 11);


    for (int i = 0; i < 11; i++){
        printf("Array value %d is equal to %d \n" , i , array[i]);
    }


    quickSort(array, 0, 10);



    for (int i = 0; i < 11; i++){
        printf("Array  sorted value %d is equal to %d \n" , i , array[i]);
    }

}