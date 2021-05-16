try:
    import collections
    testCases = int(input())
    for _ in range(testCases):
        n = int(input())
        caves = [0]*n
        c = list(map(int,input().split()))
        h = list(map(int,input().split()))
        
        for j in range(1,n+1):
            start = j-c[j-1]
            end = c[j-1]+j
            if(start < 1):start=1
            if(end > n):end=n
            for x in range(start,end+1):caves[x-1]+=1
            
        compare = lambda x, y: collections.Counter(x) == collections.Counter(y)
        if compare(caves,h):print("YES")
        else:print("NO")
except:pass
