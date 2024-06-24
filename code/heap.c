#include <stdio.h>

#define arraySize 21

int mainArray [arraySize];
int lastPosition = 1;

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

void insert(int value){

    if(lastPosition == arraySize){
        printf("Is full \n");
        return;
    }

    mainArray[lastPosition] = value;
    sift_up(mainArray, lastPosition);
    lastPosition += 1;
}

int main() {
    
    //int array [] = {0,10,29,20,18,27,28,17,26,76,16};
    int array [] = {0,1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    //sift_up(array, 6);

   // for(int i = 1; i< 10; i++){
     //   printf("Array position = %d and value = %d \n" ,i, array[i]);
    //}    


    for(int i = 1; i <= 11; i++){
        printf("last position = %d", lastPosition);
        insert(array[i]);
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }

    for(int i = 1; i<= 11; i++){
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }    


}