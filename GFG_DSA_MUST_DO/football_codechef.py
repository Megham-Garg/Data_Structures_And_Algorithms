for _ in range(int(input())):
    totalPlayers = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    scores = list()
    for i in range(totalPlayers):
        if(A[i]*20-B[i]*10 > 0):scores.append(A[i]*20-B[i]*10)
        else:scores.append(0)
    print(max(scores))
