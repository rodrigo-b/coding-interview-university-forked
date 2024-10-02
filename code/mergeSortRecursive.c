#include <stdio.h>
#include <stdlib.h>

void sort(int lo, int hi, int *array, int *auxArray){

    if(hi <= lo){
        return;
    }

    int mid = (hi + lo) / 2;

    sort(lo, hi, array, auxArray);
    sort(mid + 1, hi, array, auxArray);
    merge(lo,hi, array, auxArray);
}


void merge(int lo, int hi, int *array, int *auxArray){

    if(auxArray[hi] < auxArray[lo]){
        int aux = auxArray[hi];

    }

}

int main (){

}