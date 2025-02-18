#include <stdio.h>
#include <stdlib.h>
#define dll __declspec(dllexport)

dll void free_array(int *array);
dll int *bubble_sort(int array[], int size);
dll int *insertion_sort(int array[], int size);
dll int *selection_sort(int array[], int size);
dll int *merge(int left_array[], int right_array[], int left_size, int right_size);
dll int *merge_sort(int array[], int size);
dll void partition(int array[], int min, int max);
dll int *quick_sort(int array[], int size);
dll void heapify(int array[], int size, int i);
dll void build_heap(int array[], int size);
dll int *heap_sort(int array[], int size);
dll int *tim_sort(int array[], int size);
dll int *counting_sort(int array[], int size);
dll int *radix_sort(int array[], int size);

int main()
{ // only for testing UwU
    int array[] = {2, 3, 5, 6, 8, 9, 1, 2, 3, 5, 6, 23};
    int size = sizeof(array) / sizeof(array[0]);
    int *sorted_array = radix_sort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sorted_array[i]);
    }
    return 0;
}

dll void free_array(int *array)
{
    free(array);
}

dll int *bubble_sort(int array[], int size)
{
    // Time complexity: O(n^2)
    // boo boring
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
    // i love this beauty, sorting algorithm if we talk about elegance
    // this algo is akin to your fat little sister who eats leftovers like a hog
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

void partition(int array[], int min, int max)
{ // the real magic happens here
    if (max > min)
    { // set a pivot and if elements are bigger than that thing boom to the right of it
        // otherwise to the left
        // divide it into smaller sub arrays in place and do the same to them until the base case
        // and boom you have a sorted array
        int pivot = array[max], j = min - 1, temp;
        for (int i = min; i <= max; i++)
        {
            if (array[i] <= pivot)
            {
                j++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[j + 1];
        array[j + 1] = array[max];
        array[max] = temp;
        partition(array, min, j - 1);
        partition(array, j + 1, max);
    }
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
    // nothing to see here
    partition(sorted_array, 0, size - 1);

    return sorted_array;
}

void heapify(int array[], int size, int i)
{
    // easy way to convert an innocent array into a vicious log time heap
    int left_child = i * 2 + 1;
    int right_child = i * 2 + 2;
    int max = i;
    int temp;

    if (left_child < size && array[left_child] > array[max])
    {
        max = left_child;
    }
    if (right_child < size && array[right_child] > array[max])
    {
        max = right_child;
    }
    if (max != i)
    {
        temp = array[max];
        array[max] = array[i];
        array[i] = temp;
        heapify(array, size, max);
    }
}

void build_heap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}

dll int *heap_sort(int array[], int size)
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

    build_heap(sorted_array, size);

    for (int i = size - 1; i > 0; i--)
    {
        int temp = sorted_array[0];
        sorted_array[0] = sorted_array[i];
        sorted_array[i] = temp;
        heapify(sorted_array, i, 0);
    }

    return sorted_array;
}

dll int *counting_sort(int array[], int size)
{
    // Time complexity: O(n+k)
    if (size == 0)
    {
        return NULL;
    }

    int *sorted_array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        sorted_array[i] = array[i];
    }

    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int *counting_array = (int *)calloc((max + 1), sizeof(int));

    for (int i = 0; i < size; i++)
    {
        counting_array[array[i]]++;
    }

    int index = 0;

    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j < counting_array[i]; j++)
        {
            sorted_array[index] = i;
            index++;
        }
    }

    free(counting_array);

    return sorted_array;
}

dll int *radix_sort(int array[], int size)
{
    // Time complexity: O(nk)
    if (size == 0)
    {
        return NULL;
    }

    int *sorted_array = (int *)malloc(sizeof(int) * size);

    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int exp = 1;

    while (max / exp > 0)
    {
        int *counting_array = (int *)calloc(10, sizeof(int));

        for (int i = 0; i < size; i++)
        {
            counting_array[(array[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            // adding this way and storing gives on which index should the "digit" end
            counting_array[i] += counting_array[i - 1];
        }

        for (int i = size - 1; i >= 0; i--)
        {
            /*doing it in reverse makes sure the count is decreased and the new index-
            -for that unit or whatever placed digit is in the right place
            */
            int digit = (array[i] / exp) % 10;
            sorted_array[counting_array[digit] - 1] = array[i];
            // we decrease 1 because the index is +1 of what it should be
            counting_array[digit]--;
        }

        for (int i = 0; i < size; i++)
        {
            // copying it after each run so that the thing can be done again on a semi sorted list
            // of course on a different digit so we do exp*= 10
            array[i] = sorted_array[i];
        }

        exp *= 10;

        free(counting_array);
    }
    return sorted_array;
}
