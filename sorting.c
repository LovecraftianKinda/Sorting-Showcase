#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int size);
int* bubble_sort(int array[], int size);
double time_taken(int array[], int size);
void complexity_time(int array[], int size);

int main(){

    unsigned long n ;
    //remove it
    printf("Enter the number of elements in the array: ");

    scanf("%lu", &n);
    printf("\n");

    int* array = (int*)malloc(n*sizeof(int));
    srand (time(0));

    for (int i = 0; i<n; i++){
        array[i] = rand() % 1000;
    }

    complexity_time(array, n);

    free(array);

    return 0;
}

void print_array(int array[], int size){

    printf("The array is: ");
    for (int i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int* bubble_sort(int array[],int size){

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

double time_taken(int array[], int size){

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubble_sort(array, size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

void complexity_time(int array[], int size){

    double time = time_taken(array, size);

    printf("time taken: %fs\n", time);
}