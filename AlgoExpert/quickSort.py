def quickSort(arr, start, end):
    # print(arr, start, end)
    if(end-start<1):
        return arr
    left = start+1
    right = end
    pivot = start
    while(left<=right):
        if arr[left] > arr[pivot] and arr[right] < arr[pivot]:
            arr[left], arr[right] = arr[right], arr[left]
        if arr[left] <= arr[pivot]:
            left+=1
        if arr[right] >= arr[pivot]:
            right-=1
    arr[pivot], arr[right] = arr[right], arr[pivot]
    pivot = right
    if pivot!=end:
        arr = quickSort(arr, pivot+1 , end)
    if pivot!=start:
        arr = quickSort(arr, start, pivot-1)
    return arr
        
# O(nlogn) avg time
# O(n^2) worst case

# O(logn) space due to recursion and call on smallest subarray first