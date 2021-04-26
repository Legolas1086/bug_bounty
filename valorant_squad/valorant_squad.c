#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
                       
int convertRanks(char rank[10])
{
    if(!strcmp(rank,"iron"))
        return 1;

    else if(!strcmp(rank,"bronze"))
        return 2;

    else if(!strcmp(rank,"silver"))
        return 3;

    else if(!strcmp(rank,"gold"))
        return 4;

    else if(!strcmp(rank,"platinum"))
        return 5;

    else if(!strcmp(rank,"diamond"))
        return 6;

    else if(!strcmp(rank,"immortal"))
        return 7;

    else if(!strcmp(rank,"radiant"))
        return 8;       
    return 0;
}

int partition(int arr[25],int low,int high)
{
    int j,i = low-1;
    int pivot = arr[high];
    for(j=low;j<high;++j)
    {
        if(arr[j]>=pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    return (i+1);
}


void arrangeScore(int score_of_players[25],int low,int high)
{
    int pi;
    if(low<high)
    {
        pi = partition(score_of_players, low, high);
        
        arrangeScore(score_of_players, low, pi-1);
        arrangeScore(score_of_players, pi+1, high);
    }
    
}

int bestTeam(int n, char ranks[n][10],int communication[n])
{
    int   score_of_players[n],i,bestTeam=0;  
    for(i=0;i<n;i++){
        score_of_players[i]=(convertRanks(ranks[i])+communication[i]);
    }
     
    arrangeScore(score_of_players,0,n-1);
    
    for(i=0;i<4;i++)
        bestTeam+=score_of_players[i];
            
    return bestTeam;    
}

int main() {
    int n,i;
    scanf("%d",&n);
    
    char ranks[n][10];
    int communication[n];
    
    for(i=0;i<n;i++)
        scanf("%s",ranks[i]);
    
    for(i=0;i<n;i++)
        scanf("%d",&communication[i]);
  
    if(n<4)
    {
      printf("Cannot form a team, at least 4 players are required");
      exit(0);
    } 
    
    int result=bestTeam(n,ranks,communication);
    
    printf("%d",result);
    
    return 0;
}