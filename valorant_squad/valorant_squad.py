def convertRanks(ranks):
    
    if ranks == 'iron':
        return 1

    elif ranks == 'bronze':
        return 2

    elif ranks == 'silver':
        return 3

    elif ranks == 'gold':
        return 4

    elif ranks == 'platinum':
        return 5

    elif ranks == 'diamond':
        return 6

    elif ranks == 'immortal':
        return 7 

    elif ranks == 'radiant':
        return 8                        


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

    score_of_players = []
    for i in range(n):
        score_of_players.append(convertRanks(ranks[i])+communication[i])

    arrangeScore(score_of_players,0,n-1)
    
    bestTeam = score_of_players[0:4]
    return sum(bestTeam)


if __name__=="__main__":
    n = int(input())
    ranks = list(input().rstrip().split())
    communication = list(map(int,input().rstrip().split()))

    result = bestTeam(n,ranks,communication)
    print(result)