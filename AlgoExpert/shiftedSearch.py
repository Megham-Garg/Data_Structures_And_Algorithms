# O(log n) time
# O(1) space
def shiftedBinarySearch(array, target):
    start = 0
    end = len(array) - 1
    mid  = (start+end)//2
    while(start <= end):
        if array[mid] == target:
            return mid
        if array[start] <= array[mid]:
            if target < array[mid] and target >= array[start]:
                end = mid-1
            else:
                start=mid+1
        else:
            if target > array[mid] and target <= array[end]:
                start = mid+1
            else:
                end=mid-1
        mid  = (start+end)//2
    return -1

print(shiftedBinarySearch([45,61,71,72,73,0,1,33],33), end='')