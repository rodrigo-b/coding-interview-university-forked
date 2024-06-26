#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define arraySize 21

int mainArray [arraySize];
int lastPosition = 0;

void sift_up (int *array,int index){

    
    if(index == 1){
        return;
    } 

    int parent = index/2;

    printf("Valor do index do parent = %d \n",parent );
    printf("Valor do parent = %d \n",array[parent] );
    if(array[parent] < array[index]){
        int aux = array[parent];
        array[parent] = array[index];
        array[index] = aux;
            
    printf("Valor atualizado do parent = %d \n",array[parent] );
    printf("Valor atualizado do filgo = %d \n",array[index] );
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

int extract_max(int *anyArray){


    printf("lastPosition is equal to %d", lastPosition);
    if(lastPosition == 0){
        printf("Array is null \n");
        return -1;
    }

    int maxValue = anyArray[1];
    anyArray[1] = anyArray[lastPosition];
    anyArray[lastPosition] = -1;
    lastPosition -= 1;
    sift_down(anyArray, 1);
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

void heapify(int *arrayHeap, int arraySizeHeapify){
    
    int init = (arraySizeHeapify / 2) + 1;
    printf("init value before while= %d \n", init);
    int limit = arraySizeHeapify;
    printf("limit value before while = %d \n", limit);
    int counter = init;
    printf("counter value before while = %d \n", counter);

    
    while(counter >= 1){
            for(int i = 1; i<= arraySizeHeapify; i++){
        printf(" %d ," , arrayHeap[i]);
            }  
            printf("\n");
        printf("position  = %d  current value %d \n", counter, arrayHeap[counter]);                        
        printf("position  = %d  parent value %d \n", counter, arrayHeap[counter/2]);

        if(counter / 2 > 0){
            sift_down(arrayHeap,counter /2);
        }                            

        printf("position  = %d  changed to %d \n", counter, arrayHeap[counter/2]);                        
        counter += 1;

        printf("counter is equal to %d \n", counter);
        printf("limit is equal to %d \n", limit);

        if(counter > limit){        
            int aux = init -1;
            printf("aux  = %d   \n",aux);                        
            init = init / 2;
            printf("init  = %d   \n",init);                        
            limit = aux;
            printf("limit  = %d   \n",limit);                        
            counter = init;
        }          
    }
}

int *heap_sort(int *arrayHeap, int arraySizeHeapify){
    heapify(arrayHeap,arraySizeHeapify);
    lastPosition += 1; //this is here only because is not parameterized
  for(int i = 1; i<= arraySizeHeapify -1; i++){
        printf("notSorted position = %d and value = %d \n" ,i, arrayHeap[i]);
    }

    int *sorted = malloc(sizeof(int) * 11);

    for(int i = arraySizeHeapify - 1; i >= 1; i --){
        int max = extract_max(arrayHeap);
        printf("max = %d and i value is equal to %d \n", max, i);
        sorted[i] = max;
    }    
    
    return sorted;
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

    //int maxValue = extract_max();
    
    //printf("MaxValue = %d \n", maxValue);
    for(int i = 1; i< arraySized -1; i++){
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }  
    
    printf("the number of elements stored is equal to %d \n", get_size());

    int removedValue = removeHeap(2);
    printf("Removed value is equal to %d \n", removedValue);

    for(int i = 1; i< arraySized -1; i++){
        printf("Array position = %d and value = %d \n" ,i, mainArray[i]);
    }  

    int array3 [] = {0,10,29,20,18,27,28,17,26,76,16};
    int arraySize3 = sizeof(array3)/sizeof(array3[1]);
    //heapify(array3, arraySize3 - 1);

    //printf("array size = %d \n", arraySize3);
       //for(int i = 1; i<= arraySize3 -1; i++){
        //printf("Array3 position = %d and value = %d \n" ,i, array3[i]);
    //}  

    int  *sortedArray = heap_sort(array3,arraySize3);

    printf("array size = %d \n", arraySize3);
       for(int i = 1; i<= arraySize3 -1; i++){
        printf("sorted position = %d and value = %d \n" ,i, sortedArray[i]);
    }

}