# O(maxDepth) space
# O(all elements) time
def ProductSum(arr):
    return productHelper(arr, 1)

def productHelper(arr, depth):
    sum = 0
    for ele in arr:
        if(isinstance(ele, int)):
            sum+=ele
        else:
            sum+=productHelper(ele, depth+1)
    return sum * depth

print(ProductSum([5,2,[7,-1],3,[6,4,[-13,8]]]))