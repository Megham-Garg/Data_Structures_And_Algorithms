i,j = 0,0
size = input()

n,m = int(size.split(" ")[0]),int(size.split(" ")[1])  # separate length and height of door mat
for i in range(n):
    for j in range(m):
        print("-",end="")
    print()
