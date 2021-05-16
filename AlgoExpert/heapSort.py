def heapSort(arr):
    ind = len(arr)-1
    heapify(arr)
    while ind:
        arr[ind], arr[0] = arr[0], arr[ind]
        heapify(arr[:ind-1])
        ind-=1

# O(nlogn) time
# O(1) space