#include <stdio.h>
#include <stdlib.h>

void sort(int lo, int hi, int *array, int *auxArray){

    if(hi <= lo){
        return;
    }

    int mid = (hi + lo) / 2;

    sort(lo, mid, array, auxArray);
    sort(mid + 1, hi, array, auxArray);
    merge(lo,hi, mid, array, auxArray);
}


void merge(int lo, int hi, int mid,int *array, int *auxArray){

    for(int i = lo; i <= hi; i++){
        auxArray[i] = array[i];
    }

    int low = lo;
    int higher = mid + 1;

    for(int i = lo; i <= hi; i++){

        if(low > mid){
            array[i] = auxArray[higher];
            higher++;
        }
        else if(higher > hi){
            array[i] = auxArray[low];
            low++;
        }
        else if(array[higher] < auxArray[low] ){
             array[i] = auxArray[higher];
             higher++;
        } else {
              array[i] = auxArray[low];
              low++;
        }

    }

}

int main (){

    int array [] = {2,8,22,33,6,9,3,21,22,90,60};

    int arrayAux [11];

    int low = 0;
    int high = 10;

    sort(low,high,array, arrayAux);

    for(int i = 0; i < 11; i++){
        printf("array value = %d \n", array[i]);
    }

}