#include <stdio.h>
#include <stdbool.h>

#define arraySize 21

int mainArray [arraySize];
int lastPosition = 0;

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

    lastPosition += 1;
    mainArray[lastPosition] = value;
    sift_up(mainArray, lastPosition);    
}

int get_max(){

    if(lastPosition == 0){
        printf("array is empty \n");
        return 0;
    }

    return mainArray[1];
}

int get_size(){
    return lastPosition;
}

bool is_empty(){

    if(lastPosition == 0){
        return true;
    }

    return false;
}

void sift_down(int *array, int index){

    int firstLeaf = (get_size() / 2) + 1;
    if(index >= (firstLeaf)){
        return;
    }

    int leftChild = index * 2;
    int rightChild = (index * 2) + 1;
    int grater  = array[leftChild] > array[rightChild] ? leftChild : rightChild;

    if(array[grater] > array[index]){
        int aux = array[grater];
        array[grater] = array[index];
        array[index] = aux;
        sift_down(array,grater);
    }

}

int extract_max(){

    if(lastPosition == 0){
        printf("Array is null");
        return -1;
    }

    int maxValue = mainArray[1];
    mainArray[1] = mainArray[lastPosition];
    mainArray[lastPosition] = -1;
    lastPosition -= 1;
    sift_down(mainArray, 1);
    return maxValue;
}

int removeHeap(int index) {
    
    int removedValue = mainArray[index];
    if(index != 1){        
        mainArray[index] = mainArray[lastPosition];
        mainArray[lastPosition] = -1;
        lastPosition -= 1;
    }

    sift_down(mainArray,index); 

    return removedValue;   
}

int main() {
            
    printf("isEmpty?  %s", is_empty()? "true \n" : "false \n");

    int array [] = {0,10,29,20,18,27,28,17,26,76,16};
    //int array [] = {0,1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    //sift_up(array, 6);

   // for(int i = 1; i< 10; i++){
     //   printf("Array position = %d and value = %d \n" ,i, array[i]);
    //}    

    int arraySized = sizeof(array)/sizeof(array[0]);
    printf("arraySized = %d", arraySized);

    for(int i = 1; i < arraySized; i++){
        printf("last position = %d", lastPosition);
        insert(array[i]);
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }



    for(int i = 1; i< arraySized; i++){
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }    

    printf("the max value is equal to %d \n", get_max());
    printf("the number of elements stored is equal to %d \n", get_size());
    printf("isEmpty?  %s", is_empty()? "true \n" : "false \n");

    int maxValue = extract_max();
    
    printf("MaxValue = %d \n", maxValue);
    for(int i = 1; i< arraySized -1; i++){
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }  
    
    printf("the number of elements stored is equal to %d \n", get_size());

    int removedValue = removeHeap(2);
    printf("Removed value is equal to %d \n", removedValue);

    for(int i = 1; i< arraySized -1; i++){
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }  
}