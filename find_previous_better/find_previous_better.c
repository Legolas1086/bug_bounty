#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void previousBest(int n,int ranks[25])
{
    int i,j=0;
    int stack[25],top=-1,previos_greater[25];
    for(i=0;i<n;++i)
    {
        while(top>=0)
        {
            if(stack[top]>ranks[i])
            {
                previos_greater[j++]=stack[top];
                break;
            }
            else
            {
                top--;
            }
        }
        if(top<0)
            previos_greater[j++]=-1;
        
        stack[++top]=ranks[i];
    }
    
    for(i=0;i<j;++i)
    {
        printf("%d ",previos_greater[i]);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int ranks[n];
    for(i=0;i<n;++i)
        scanf("%d",&ranks[i]);
                
    previousBest(n,ranks);
    
    return 0;
}