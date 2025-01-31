#include <stdio.h>
#include <stdlib.h>
#define dll __declspec(dllexport)

int main(){
    return 0;
}

dll int* bubble_sort(int array[],int size){
    int i, j, temp, flag;
    for (i = 0 ; i<size ; i ++){
        if (flag == 0){
            break;
        }
        flag = 0;
        for (j = 0; j<size-1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
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
    int i, min, j, temp;
    for (i=0 ; i < size ; i++){
        min = i;
        for (j = i+1 ; j < size ; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }

        if (min != i){
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        }
    }
    return array;
}