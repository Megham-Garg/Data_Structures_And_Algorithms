def quickSelect(arr, k):
    print(arr)
    if(len(arr)==0):
        return float("inf")
    
    left=1
    right=len(arr)-1
    pivot=0
    while(left <= right):
        print(left)
        if arr[left] <= arr[pivot]:
            left+=1
        elif arr[right] > arr[pivot]:
            right-=1
        else:
            arr[right], arr[left] = arr[left], arr[right]
            left+=1
            right-=1
    arr[right], arr[pivot] = arr[pivot], arr[right]
    if right == k-1:
        return arr[right]
    if k-1 > right:
        return quickSelect(arr[right+1:], k-right-1)
    return quickSelect(arr[:right], k)

# o(n) best
# o(n) avg
# o(n^2) worst
print(quickSelect([8,5,2,9,7,6,3],3))