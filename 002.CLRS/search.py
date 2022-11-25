import time
import random

list_to_search = []
for i in range(100000):
    list_to_search.append(random.randint(1, 100000))


# Binary search using bitwise operations
def binary_search(list_to_search, item_to_search):
    """Returns the index of the item to search"""
    low = 0
    high = len(list_to_search) - 1
    while low <= high:
        mid = (low + high) >> 1
        guess = list_to_search[mid]
        if guess == item_to_search:
            return mid
        if guess > item_to_search:
            high = mid - 1
        else:
            low = mid + 1
    return None


# Fibonacci search
def fibonacci_search(list_to_search, item_to_search):
    """Returns the index of the item to search"""
    fib_m2 = 0
    fib_m1 = 1
    fib = fib_m2 + fib_m1
    while fib < len(list_to_search):
        fib_m2 = fib_m1
        fib_m1 = fib
        fib = fib_m2 + fib_m1
    offset = -1
    while fib > 1:
        i = min(offset + fib_m2, len(list_to_search) - 1)
        if list_to_search[i] < item_to_search:
            fib = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib - fib_m1
            offset = i
        elif list_to_search[i] > item_to_search:
            fib = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib - fib_m1
        else:
            return i
    if fib_m1 and list_to_search[offset + 1] == item_to_search:
        return offset + 1
    return None


# time the binary search
start_time = time.time()
for i in range(20):
    binary_search(list_to_search, random.randint(1, 100000))
end_time = time.time()
print("Binary search time: ", end_time - start_time)

# time the fibonacci search
start_time = time.time()
for i in range(20):
    fibonacci_search(list_to_search, random.randint(1, 100000))
end_time = time.time()
print("Fibonacci search time: ", end_time - start_time)
