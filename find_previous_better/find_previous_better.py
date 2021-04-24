def previousBest(n,ranks):
    stack = []
    previous_greater = []
    for i in range(n):
        while stack:
            if stack[-1] > ranks[i]:
                previous_greater.append(stack[-1])
                break

            else:
                stack.pop()

        if not stack:
            previous_greater.append(-1)

        stack.append(ranks[i])

    for i in previous_greater:
        print(i,end=" ")
        

if __name__=="__main__":
    n = int(input())
    ranks = list(map(int,input().rstrip().split()))

    previousBest(n,ranks)
    