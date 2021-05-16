def rangeSearch(arr, target):
    range_ans = [None, None]

    l, r = 0, len(arr)-1
    while l <= r:
        mid = (l+r)//2
        if arr[mid] == target:
            range_ans[0]=mid
            r=mid-1
            continue
        elif arr[mid] > target:
            r=mid-1
            continue
        else:
            l=mid+1

    l, r = 0, len(arr)-1
    while l <= r:
        mid = (l+r)//2
        if arr[mid] == target:
            range_ans[1]=mid
            l=mid+1
            continue
        elif arr[mid] > target:
            r=mid-1
            continue
        else:
            l=mid+1

    return range_ans
# O(log(n)) time
# O(1) space
print(rangeSearch([0,1,21,33,45,45,45,45,45,45,56,67,89], 45))