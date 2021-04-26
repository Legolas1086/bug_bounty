#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int prices(char extras[25][10],int len)
{
    int i,total_cost=0;
    
    for(i=0;i<len;++i)
    {
        if(!strcmp(extras[i],"odin"))
            total_cost+=10000;
        else if(!strcmp(extras[i],"operator"))
            total_cost+=8000;
        else if(!strcmp(extras[i],"bulldog"))
            total_cost+=7000;
        else if(!strcmp(extras[i],"bucky"))
            total_cost+=5000;
        else if(!strcmp(extras[i],"ghost"))
            total_cost+=2000;
        else if(!strcmp(extras[i],"ares"))
            total_cost+=9000;
    }
    return total_cost;
}

int findExtras(int n,char guns[25][10])
{
    char extras[25][10];
    int i,j,k=0;

    for(i=0;i<n-1;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(!strcmp(guns[i],guns[j]))
            {
                strcpy(extras[k],guns[j]);
                ++k;
                break;
            }
        }
    }

    int total_cost=prices(extras,k);
    return total_cost;
}

int main() {
    int n,i;
    scanf("%d",&n);
    
    char guns[n][10];
    for(i=0;i<n;++i)
    {
        scanf("%s",guns[i]);
    }
    
    int result = findExtras(n,guns);
    
    printf("%d",result);
    
    return 0;
}