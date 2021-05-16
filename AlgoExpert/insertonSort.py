def insertionSort(arr):
    for ind in range(1, len(arr)):
        ptr = ind-1
        if arr[ind] >= arr[ptr]:
            continue
        while(ptr > -1 and arr[ptr] > arr[ind]):
            arr[ptr], arr[ind] = arr[ind], arr[ptr]
            ind-=1
            ptr-=1

        print(arr)

# O(n^2) time
# O(1) space