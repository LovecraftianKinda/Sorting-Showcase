#include <stdio.h>
#include <stdlib.h>
#define dll __declspec(dllexport)

int main(){
    return 0;
}

dll void free_memory(int* array) {
    free(array);
}

dll int* bubble_sort(int array[],int size){

    int i, j, temp;

    for (i = 0 ; i<size ; i ++){
        for (j = 0; j<size-1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return array;
}

dll int* insertion_sort(int array[],int size){

    int i,j,temp;

    for (i = 1 ; i < size ; i++ ){
        for (j = i; j > 0 ; j--){
            if (array[j] < array[j-1]) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            } else{
                break;
            }
        }
    }
    return array;
}


dll int* selection_sort(int array[], int size){
    
    return array;
}