#include <stdio.h>
#include <stdlib.h>
#define dll __declspec(dllexport)

dll void free_array(int *array)
{
    free(array);
}

dll int *bubble_sort(int array[], int size);
dll int *insertion_sort(int array[], int size);
dll int *selection_sort(int array[], int size);
dll int *merge(int left_array[], int right_array[], int left_size, int right_size);
dll int *merge_sort(int array[], int size);
dll int *quick_sort(int array[], int size);

int main()
{

    return 0;
}

dll int *bubble_sort(int array[], int size)
{
    // Time complexity: O(n^2)
    if (size == 0)
    {
        return NULL;
    }
    int *sorted_array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        sorted_array[i] = array[i];
    }
    int temp, flag = 1;
    for (int i = 0; i < size; i++)
    {
        if (flag == 0)
        {
            break;
        }
        flag = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (sorted_array[j] > sorted_array[j + 1])
            {
                temp = sorted_array[j];
                sorted_array[j] = sorted_array[j + 1];
                sorted_array[j + 1] = temp;
                flag = 1;
            }
        }
    }
    return sorted_array;
}

dll int *insertion_sort(int array[], int size)
{
    // Time complexity: O(n^2)
    if (size == 0)
    {
        return NULL;
    }
    int *sorted_array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        sorted_array[i] = array[i];
    }
    int temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (sorted_array[j] < sorted_array[j - 1])
            {
                temp = sorted_array[j];
                sorted_array[j] = sorted_array[j - 1];
                sorted_array[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    return sorted_array;
}

dll int *selection_sort(int array[], int size)
{
    // Time complexity: O(n^2)
    if (size == 0)
    {
        return NULL;
    }
    int *sorted_array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        sorted_array[i] = array[i];
    }
    int min, temp;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (sorted_array[j] < sorted_array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = sorted_array[i];
            sorted_array[i] = sorted_array[min];
            sorted_array[min] = temp;
        }
    }
    return sorted_array;
}

int *merge(int left_array[], int right_array[], int left_size, int right_size)
{
    int *sorted_array = (int *)malloc(sizeof(int) * (left_size + right_size));
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
    {
        if (left_array[i] <= right_array[j])
        {
            sorted_array[k] = left_array[i];
            i++;
        }
        else
        {
            sorted_array[k] = right_array[j];
            j++;
        }
        k++;
    }
    for (; i < left_size; i++)
    {
        sorted_array[k] = left_array[i];
        k++;
    }
    for (; j < right_size; j++)
    {
        sorted_array[k] = right_array[j];
        k++;
    }
    return sorted_array;
}

dll int *merge_sort(int array[], int size)
{
    // Time complexity: O(nlogn)
    if (size == 0)
    {
        return NULL;
    }

    if (size > 1)
    {
        int left_size = size / 2;
        int right_size = size - left_size;
        int *left_array = (int *)malloc(left_size * sizeof(int));
        int *right_array = (int *)malloc(right_size * sizeof(int));

        for (int i = 0; i < left_size; i++)
        {
            left_array[i] = array[i];
        }
        for (int i = 0; i < right_size; i++)
        {
            right_array[i] = array[left_size + i];
        }

        int *sorted_left = merge_sort(left_array, left_size);
        int *sorted_right = merge_sort(right_array, right_size);

        int *merged_array = merge(sorted_left, sorted_right, left_size, right_size);

        free(left_array);
        free(right_array);

        if (left_size > 1)
        {
            free(sorted_left);
        }
        if (right_size > 1)
        {
            free(sorted_right);
        }

        return merged_array;
    }
    return array;
}

dll int *quick_sort(int array[], int size)
{
    // Time complexity: O(nlogn)
    if (size == 0)
    {
        return NULL;
    }
    int *sorted_array = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        sorted_array[i] = array[i];
    }
    if (size == 1)
    {
        return sorted_array;
    }
    int a = sorted_array[0];
    int b = sorted_array[size - 1];
    int c = sorted_array[size / 2];

    int pivot = (a > b && b > c) || (c > b && b > a) ? size - 1 : (b > a && a > c) || (c > a && a > b) ? 0
                                                                                                       : size / 2;

    int *left_array = (int *)malloc(sizeof(int) * size);
    int *right_array = (int *)malloc(sizeof(int) * size);

    int left_i = 0;
    int right_i = 0;

    for (int i = 0; i < pivot; i++)
    {
        if (sorted_array[i] <= sorted_array[pivot])
        {
            left_array[left_i] = sorted_array[i];
            left_i++;
        }
        else
        {
            right_array[right_i] = sorted_array[i];
            right_i++;
        }
    }

    for (int i = pivot + 1; i < size; i++)
    {
        if (sorted_array[i] <= sorted_array[pivot])
        {
            left_array[left_i] = sorted_array[i];
            left_i++;
        }
        else
        {
            right_array[right_i] = sorted_array[i];
            right_i++;
        }
    }

    int *sorted_left = quick_sort(left_array, left_i);
    int *sorted_right = quick_sort(right_array, right_i);

    free(left_array);
    free(right_array);

    for (int i = 0; i < left_i; i++)
    {
        sorted_array[i] = sorted_left[i];
    }

    for (int i = 0; i < right_i; i++)
    {
        sorted_array[i + left_i] = sorted_right[i];
    }

    if (left_i > 1)
    {
        free(sorted_left);
    }
    if (right_i > 1)
    {
        free(sorted_right);
    }

    return sorted_array;
}