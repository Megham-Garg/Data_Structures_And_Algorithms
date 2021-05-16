from time import time

startTime = time()

def bubbleSort(arr):
    flag = True
    end = len(arr)
    while flag:
        flag = False
        for ind in range(1,end):
            if arr[ind] < arr[ind-1]:
                arr[ind], arr[ind-1] = arr[ind-1], arr[ind]
                flag = True
        end-=1
        print(arr)
    return

# O(n^2) time
# O(1) space
# Inplace

endTime = time()
runTime = endTime - startTime
print(runTime)