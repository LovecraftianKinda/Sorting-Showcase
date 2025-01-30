import ctypes
import os
import random
import time

dll = ctypes.CDLL(os.path.abspath("sorting.dll"))

dll.bubble_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
dll.bubble_sort.restype = ctypes.POINTER(ctypes.c_int)

dll.free_memory.argtypes = [ctypes.POINTER(ctypes.c_int)]
dll.free_memory.restype = None

#this is temporary
n = int(input("enter number :"))

array = [random.randint(0, n) for i in range(n)]


c_array = (ctypes.c_int * len(array))(*array)

time_start = time.time()
sorted_array_ptr = dll.bubble_sort(c_array, len(array))

time_end = abs(time.time() - time_start)

sorted_array = [sorted_array_ptr[i] for i in range(len(array))]

print(f"Time taken: {time_end}s")



dll.free_memory(sorted_array_ptr)
