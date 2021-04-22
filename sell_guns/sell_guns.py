def prices(extras):
    cost = []
    for i in range(len(extras)):
        if extras[i] == 'odin':
            cost.append(10000)

        elif extras[i] == 'operator':
            cost.append(8000)

        elif extras[i] == 'bulldog':
            cost.append(7000)

        elif extras[i] == 'bucky':
            cost.append(5000)

        elif extras[i] == 'ghost':
            cost.append(2000)                
            
    return cost


def findExtras(n,guns):
    extras = []
    for i in range(n-1):
        for j in range(i+1,n):
            if guns[i] == guns[j]:
                extras.append(guns[j])
                break

    costs = prices(extras)

    total_cost = 0
    for i in range(len(costs)):
        total_cost += costs[i]

    return total_cost    
               


if __name__=="__main__":
    n = int(input())
    guns = list(input().rstrip().split())

    result = findExtras(n,guns)
    print(result)