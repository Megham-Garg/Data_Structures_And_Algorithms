def arrDivider(mainArr, auxArr, start, end):
    if start == end:
        return mainArr
    mid = (start+end)//2
    arrDivider(auxArr, mainArr, start, mid)
    arrDivider(auxArr, mainArr, mid+1, end)
    mergeArr(mainArr, auxArr, start, mid, end)

def mergeArr(mainArr, auxArr, start, mid, end):
    left = start
    right = mid+1
    while left <= mid and right <= end:
        if auxArr[left] <= auxArr[right]:
            mainArr[start]=auxArr[left]
            left+=1
        else:
            mainArr[start]=auxArr[right]
            right+=1
        start+=1
    while left <= mid:
        mainArr[start]=auxArr[left]
        left+=1
        start+=1
    while right <= end:
        mainArr[start]=auxArr[right]
        right+=1
        start+=1

# O(nlogn) time
# O(n) space
def mergeSort(arr):
    auxArr = arr.copy()
    arrDivider(arr, auxArr, 0, len(arr)-1)
    return arr
    
print(mergeSort([8,5,2,9,5,6,3]))