def findSmallest(arr, ind):
    smallest = arr[ind]
    while ind < len(arr):
        if arr[ind] < arr[smallest]:
            smallest = ind
    return smallest

def selectionSort(arr):
    ptr = -1
    while ptr != len(arr)-1:
        smallest = findSmallest(arr, ptr+1)
        arr[ptr+1], arr[smallest] = arr[smallest], arr[ptr+1]
        ptr+=1
    return

# O(1) space
# O(n^2) time