import ctypes
import os
import random
import time

dll = ctypes.CDLL(os.path.abspath("sorting.dll"))
dll.free_array.argtypes = [ctypes.POINTER(ctypes.c_int)]
dll.free_array.restype = None


def template(func, array):

    func.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
    func.restype = ctypes.POINTER(ctypes.c_int)
    c_array = (ctypes.c_int * len(array))(*array)
    time_start = time.time()
    sorted_array_ptr = func(c_array, len(array))
    time_end = abs(time.time() - time_start)
    sorted_array = [sorted_array_ptr[i] for i in range(len(array))]
    print(f"Time taken: {time_end}s in {func.__name__}")

    dll.free_array(sorted_array_ptr)

    return sorted_array, time_end


n = int(input("enter number :"))

array = [random.randint(0, n) for i in range(n)]

bubble_sort_array, bubble_sort_time = template(dll.bubble_sort, array)
selection_sort_array, selection_sort_time = template(dll.selection_sort, array)
insertion_sort_array, insertion_sort_time = template(dll.insertion_sort, array)
merge_sort_array, merge_sort_time = template(dll.merge_sort, array)
quick_sort_array, quick_sort_time = template(dll.quick_sort, array)
heap_sort_array, heap_sort_time = template(dll.heap_sort, array)
counting_sort_array, counting_sort_time = template(dll.counting_sort, array)
radix_sort_array, radix_sort_time = template(dll.radix_sort, array)
bucket_sort_array, bucket_sort_time = template(dll.bucket_sort, array)
