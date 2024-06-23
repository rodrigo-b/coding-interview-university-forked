#include <stdio.h>




void sift_up (int *array,int index){

    
    if(index == 1){
        return;
    } 
    
    int parent = index/2;

    printf("Valor do parent = %d \n",parent );
    if(array[parent] < array[index]){
        int aux = array[parent];
        array[parent] = array[index];
        array[index] = aux;
        sift_up(array, parent);
    }

}

int main() {
    
    int array [] = {0,10,29,20,18,27,28,17,26,76,16};

    sift_up(array, 6);

    for(int i = 1; i< 10; i++){
        printf("Array position = %d and value = %d \n" ,i, array[i]);
    }    



}