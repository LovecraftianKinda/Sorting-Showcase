import ctypes
import os
import random
import time

dll = ctypes.CDLL(os.path.abspath("sorting.dll"))

dll.bubble_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
dll.bubble_sort.restype = ctypes.POINTER(ctypes.c_int)

dll.selection_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
dll.selection_sort.restype = ctypes.POINTER(ctypes.c_int)

dll.insertion_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
dll.insertion_sort.restype = ctypes.POINTER(ctypes.c_int)

dll.free_memory.argtypes = [ctypes.POINTER(ctypes.c_int)]
dll.free_memory.restype = None

n = int(input("enter number :"))

array = [random.randint(0, n) for i in range(n)]

def template(func,array):
    c_array = (ctypes.c_int * len(array))(*array)
    time_start = time.time()
    sorted_array_ptr = func(c_array, len(array))
    time_end = abs(time.time() - time_start)
    sorted_array = [sorted_array_ptr[i] for i in range(len(array))]
    print(f"Time taken: {time_end}s in {func} and the sorted array is {sorted_array}")
    return sorted_array,time_end

bubble_sort_array,bubble_sort_time = template(dll.bubble_sort,array)
selection_sort_array,selection_sort_time = template(dll.selection_sort,array)
insertion_sort_array,insertion_sort_time = template(dll.insertion_sort,array)
