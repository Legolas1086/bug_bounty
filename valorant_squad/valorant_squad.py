def convertRanks(n,ranks):
    for i in range(n):
        if ranks[i] == 'iron':
            ranks[i] = 1

        elif ranks[i] == 'bronze':
            ranks[i] = 2

        elif ranks[i] == 'silver':
            ranks[i] = 3

        elif ranks[i] == 'gold':
            ranks[i] = 4

        elif ranks[i] == 'platinum':
            ranks[i] = 5

        elif ranks[i] == 'diamond':
            ranks[i] = 6

        elif ranks[i] == 'immortal':
            ranks[i] = 7 

        elif ranks[i] == 'radiant':
            ranks[i] = 8                        

    return ranks


def partition(arr, low, high):
    i = (low-1)         
    pivot = arr[high]    
    for j in range(low, high):
        if arr[j] >= pivot:
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
  
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)    


   
def arrangeScore(score_of_players,low,high):
    if len(score_of_players) == 1:
        return score_of_players
    if low < high:
        pi = partition(score_of_players, low, high)
  
        arrangeScore(score_of_players, low, pi-1)
        arrangeScore(score_of_players, pi+1, high)




def bestTeam(n,ranks,communication):
    converted_ranks = convertRanks(n,ranks)

    score_of_players = []
    for i in range(n):
        score_of_players.append(converted_ranks[i]+communication[i])

    arrangeScore(score_of_players,0,n-1)
    
    bestTeam = score_of_players[0:4]
    return sum(bestTeam)


if __name__=="__main__":
    n = int(input())
    ranks = list(input().rstrip().split())
    communication = list(map(int,input().rstrip().split()))

    result = bestTeam(n,ranks,communication)
    print(result)
    
