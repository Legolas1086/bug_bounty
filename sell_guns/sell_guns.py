def prices(extras):
    total_cost = 0
    for i in range(len(extras)):
        if extras[i] == 'odin':
            total_cost += 10000

        elif extras[i] == 'operator':
            total_cost += 8000

        elif extras[i] == 'bulldog':
            total_cost += 7000

        elif extras[i] == 'bucky':
            total_cost += 5000

        elif extras[i] == 'ghost':
            total_cost += 2000

        elif extras[i] == 'ares':
            total_cost += 9000                  
            
    return total_cost


def findExtras(n,guns):
    extras = []
    for i in range(n-1):
        for j in range(i+1,n):
            if guns[i] == guns[j]:
                extras.append(guns[j])
                break

    total_cost = prices(extras)

    return total_cost    
               


if __name__=="__main__":
    n = int(input())
    guns = list(input().rstrip().split())

    result = findExtras(n,guns)
    print(result)