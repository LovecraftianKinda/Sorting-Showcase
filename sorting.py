import os
import time
import random
import ctypes
import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk

dll = ctypes.CDLL(os.path.abspath("sorting.dll"))
dll.free_array.argtypes = [ctypes.POINTER(ctypes.c_int)]
dll.free_array.restype = None

x = []
y = []
current_time = 0
n = 1
function = dll.bubble_sort
incremental_value = 1000
currently_plotting = False


def set_function(choice):
    global function
    if choice in function_names:
        function = function_names[choice]


def on_select(event):
    global currently_plotting
    choice = options.index(var.get()) + 1
    set_function(choice)
    currently_plotting = True
    update_plot()


function_names = {
    1: dll.bubble_sort,
    2: dll.selection_sort,
    3: dll.insertion_sort,
    4: dll.merge_sort,
    5: dll.quick_sort,
    6: dll.heap_sort,
    7: dll.counting_sort,
    8: dll.radix_sort,
    9: dll.bucket_sort,
}


def return_time(func, array):

    func.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
    func.restype = ctypes.POINTER(ctypes.c_int)
    c_array = (ctypes.c_int * len(array))(*array)
    time_start = time.time()
    sorted_array_ptr = func(c_array, len(array))
    time_end = abs(time.time() - time_start)
    [sorted_array_ptr[i] for i in range(len(array))]
    # print(f"Time taken: {time_end}s in {func.__name__}")
    dll.free_array(sorted_array_ptr)

    return time_end


def update_plot():
    global current_time
    global incremental_value
    global currently_plotting
    global x
    global y
    global n
    if currently_plotting:
        dropdown.pack_forget()
        if current_time < 1:
            n += incremental_value
            current_time = return_time(function, generate_int_array(n))
            y.append(current_time)
            x.append(n)
            ax.clear()
            ax.set_xlim(0, 100 + (n))
            ax.set_ylim(0, 0.2 + (current_time))
            ax.set_title(f"{function.__name__} algorithm")
            ax.set_xlabel("Number of elements")
            ax.set_ylabel("Time taken (s)")
            ax.relim()
            ax.autoscale_view()
            ax.plot(x, y)
            canvas.draw()
            root.after(100, update_plot)
        else:
            dropdown.pack(side=tk.BOTTOM)
            currently_plotting = False


def generate_int_array(n):
    return [random.randint(0, n) for i in range(n)]


def on_closing(root):
    root.quit()
    root.destroy()


root = tk.Tk()
root.geometry("800x600")
root.title("Time Graph")

fig, ax = plt.subplots()
ax.set_xlim(0, 1)
ax.set_ylim(0, 1)

frame = tk.Frame(root)


options = [f"{i.__name__}" for i in function_names.values()]
var = tk.StringVar(root)
var.set(options[0])
dropdown = tk.OptionMenu(root, var, *options, command=on_select)
dropdown.pack(side=tk.BOTTOM)

canvas = FigureCanvasTkAgg(fig, master=frame)
canvas.get_tk_widget().pack()

toolbar = NavigationToolbar2Tk(canvas, root)
toolbar.update()
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)

update_plot()

frame.pack()

dropdown.update()
dropdown.pack()

root.protocol("WM_DELETE_WINDOW", lambda: on_closing(root))
root.mainloop()
